#include "Game.h"

/* Thread for listen comands
 * Input: pvParam - thread_id
 * Output: - */
DWORD WINAPI Listener(PVOID pvParam) {
    HANDLE hEvent = OpenEvent(SYNCHRONIZE, FALSE, L"MyEvent");

    DWORD dwWaitResult(WAIT_TIMEOUT);
    while (dwWaitResult != WAIT_OBJECT_0) {
        dwWaitResult = WaitForSingleObject(hEvent, 1);
        PostThreadMessage(*(DWORD*)pvParam, WM_CHAR, _getch(), 0);
    }

    ExitThread(0);
}

Game::Game() : count(0), speed(101) {
    InitConsole();  
}

Game::~Game() {
    SetEvent(hEvent);       //For close thread
    CloseHandle(hThread);   //Close hendle thread
    CloseHandle(hEvent);    //Close hendle event
    ReleaseDC(hWnd, hDC);   //Free context
}

/* Init kernel objects
 * Input: -
 * Output: -	 */
void Game::InitThread() {
    thread_id = GetCurrentThreadId();
    hThread = CreateThread(NULL, 0, Listener, &thread_id, 0, NULL);

    if (hThread == NULL) {
        throw KernelObjectException("Error Thread");
    }
}

void Game::InitEvent() {
    hEvent = CreateEvent(NULL, TRUE, FALSE, L"MyEvent");
    ResetEvent(hEvent);

    if (hEvent == NULL) {
        throw KernelObjectException("Error Event");
    }
}

void Game::InitConsole() {
    hWnd = GetConsoleWindow(); //Get descriptor consol window 
    hDC = GetDC(hWnd); //Get context for descriptor
}

/* Set random coordinates for fruit on scene
 * Input: array of fruit
 * Output: array of fruit with coordinates	 */
void Game::NewFruit(std::vector<Fruit>& fruits) {
    Random object_random;
    object_random.initGenerator();
    int x = object_random.random(31, 500);
    int y = object_random.random(31, 500);
    fruits.push_back({x, y});
}

/* Event handler
 * Input: key, snake
 * Output: modified	snake */
void Game::Events(WPARAM param, Snake& object_snake) {
    switch (param) {
    case 27: {
        throw GameProcessException("Exit");
        break;
    }
    case 72: {
        object_snake.SetVector(1);  //top
        break;
    }
    case 77: {
        object_snake.SetVector(2);  //right
        break;
    }
    case 80: {
        object_snake.SetVector(3);  //bottom
        break;
    }
    case 75: {
        object_snake.SetVector(0);  //left
        break;
    }
    }
}

/* Collision handler
 * Input: snake, window, fruits
 * Output: modified snake, modified window, modified fruits */
void Game::CollisionHandling(Snake& object_snake, GameWindow& object_window, std::vector<Fruit>& fruits) {
    point place = object_snake.Move();

    if (object_window.Collision(place) || object_snake.Collision(place)) {
        throw GameProcessException("Collision with window or snake");
    }

    for (int i = 0; i < fruits.size(); i++) {
        if (fruits[i].Collision(place)) {
            object_snake.Add();
            fruits.erase(fruits.begin() + i);
            NewFruit(fruits);
            count++;

            if (speed > 10) {
                speed -= 10;
            }
        }
    }
}

/* Draw graphics
 * Input: snake, window, fruits
 * Output: modified snake, modified window, modified fruits */
void Game::Draw(Snake& object_snake, GameWindow& object_window, std::vector<Fruit>& fruits) {
    for (int i = 0; i < fruits.size(); i++) {
        fruits[i].Set(hDC);
    }
    object_window.Set(hDC);
    object_snake.Set(hDC);
    std::cout << "\t\t\t\t\t\t\t\t\t Current count - " << count;
}

/* Loop with game logic
 * Input: -
 * Output: - */
void Game::GameProcess() {
    GameWindow object_window;
    Snake object_snake;
    std::vector<Fruit> fruits;

    for (int i = 0; i < 5; i++) {
        NewFruit(fruits);
    }

    while (true) {
        system("cls");

        BodyForGame(object_snake);

        CollisionHandling(object_snake, object_window, fruits);
        Draw(object_snake, object_window, fruits);   

        Sleep(speed);
    }
}

/* Start game
 * Input: user`s name
 * Output: count */
unsigned int Game::StartGame(std::string name) {
    
    try {
        InitEvent();
        InitThread();
        GameProcess();
    }
    catch (GameProcessException object) {
        system("cls");
        std::cout << std::endl << "\tFinish: " << object.what() << std::endl;
        return count;
    }

    return 0;
}

/* Demo
 * Input: -
 * Output: - */
void Game::DemoGame() {
    GameWindow object_window;
    Snake object_snake;
    std::vector<Fruit> fruits;
    InitEvent();
    InitThread();

    for (int i = 0; i < 5; i++) {
        NewFruit(fruits);
    }

    while (true) {
        system("cls");

        BodyForDemo(object_snake, fruits);

        CollisionHandling(object_snake, object_window, fruits);
        Draw(object_snake, object_window, fruits);

        Sleep(speed);
    }
}

/* Loop`s body for demo mode
 * Input: snake
 * Output: snake */
void Game::BodyForDemo(Snake& object_snake, const std::vector<Fruit> fruits) {
    BOOL bRet;
    MSG msg;

    if ((bRet = PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) != 0) {
        if (msg.wParam == 27) {
            throw GameProcessException("Exit");
        }
    }

    //AI
    for (unsigned int i = 0; i < fruits.size(); i++) {
        if (OnX(object_snake, fruits[i])) {
            break;
        }
        if (OnY(object_snake, fruits[i])) {
            break;
        }
    }
}

/* Loop`s body for game mode
 * Input: snake
 * Output: snake */
void Game::BodyForGame(Snake& object_snake) {
    BOOL bRet;
    MSG msg;

    if ((bRet = PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) != 0) {
        Events(msg.wParam, object_snake);
    }
}

/* AI for snake on X coordinate
 * Input: snake, fruit
 * Output: snake */
bool Game::OnX(Snake& object_snake, Fruit object_fruit) {
    unsigned int vector(10);    //for new vector
    int from(0), to(0);         //for loop collision

    if (object_snake.GetHead().x == object_fruit.GetPlace().x) {    //fruit on par with a snake
        return false;
    }

    if (object_snake.GetHead().x > object_fruit.GetPlace().x) {     //fruit on the left from snake
        from = CONSTANTS::MIN_SIZE;
        to = object_snake.GetHead().x;

        if (object_snake.GetVector() == 2) {                        //opposite direction
            return OnY(object_snake, object_fruit);
        }

        vector = 0;  //left
    }
    if (object_snake.GetHead().x < object_fruit.GetPlace().x) {     //fruit on the right from snake
        from = object_snake.GetHead().x;
        to = CONSTANTS::MAX_SIZE;

        if (object_snake.GetVector() == 0) {                        //opposite direction
            return OnY(object_snake, object_fruit);
        }

        vector = 2;  //right
    }

    for (int x = from; x < to; x++) {   //check of straight let
        if (object_snake.Collision({ x, object_snake.GetHead().y })) {
            return false;
        }
    }

    object_snake.SetVector(vector);
    return true;
}

/* AI for snake on Y coordinate
 * Input: snake, fruit
 * Output: snake */
bool Game::OnY(Snake& object_snake, Fruit object_fruit) {
    unsigned int vector(10);    //for new vector
    int from(0), to(0);         //for loop collision

    if (object_snake.GetHead().y == object_fruit.GetPlace().y) {    //fruit on par with a snake
        return true;
    }

    if (object_snake.GetHead().y > object_fruit.GetPlace().y) {     //fruit on the top from snake
        from = CONSTANTS::MIN_SIZE;
        to = object_snake.GetHead().y;

        if (object_snake.GetVector() == 3) {                        //opposite direction
            return OnX(object_snake, object_fruit);
        }

        vector = 1;  //top
    }

    if (object_snake.GetHead().y < object_fruit.GetPlace().y) {     //fruit on the bottom from snake
        from = object_snake.GetHead().y;
        to = CONSTANTS::MAX_SIZE;

        if (object_snake.GetVector() == 1) {                        //opposite direction
            return OnX(object_snake, object_fruit);
        }

        vector = 3;  //bottom
    }

    for (int y = from; y < to; y++) {       //check of straight let
        if (object_snake.Collision({ object_snake.GetHead().x, y })) {
            return false;
        }
    }

    object_snake.SetVector(vector);
    return true;
}