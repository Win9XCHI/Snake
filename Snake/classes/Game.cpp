#include "Game.h"

DWORD WINAPI Listener(PVOID pvParam) {
    HANDLE hEvent = OpenEvent(SYNCHRONIZE, FALSE, L"MyEvent");

    DWORD dwWaitResult(WAIT_TIMEOUT);
    while (dwWaitResult != WAIT_OBJECT_0) {
        dwWaitResult = WaitForSingleObject(hEvent, 1);
        PostThreadMessage(*(DWORD*)pvParam, WM_CHAR, _getch(), 0);
    }

    return 0;
}

Game::Game() : count(0) {
    InitConsole();  
}

Game::~Game() {
    SetEvent(hEvent);
    CloseHandle(hThread);
    CloseHandle(hEvent);
    ReleaseDC(hWnd, hDC); //Free context
}

void Game::InitThread() {
    thread_id = GetCurrentThreadId();
    hThread = CreateThread(NULL, 0, Listener, &thread_id, 0, NULL);
    if (hThread == NULL) {
        throw "Error Thread";
    }
}

void Game::InitEvent() {
    hEvent = CreateEvent(NULL, TRUE, FALSE, L"MyEvent");
    if (hEvent == NULL) {
        throw "Error Event";
    }
}

void Game::InitConsole() {
    hWnd = GetConsoleWindow(); //Get descriptor consol window 
    hDC = GetDC(hWnd); //Get context for descriptor
}


void Game::NewFruit(std::vector<Fruit>& fruits) {
    Random object_random;
    object_random.initGenerator();
    int x = object_random.random(31, 500);
    int y = object_random.random(31, 500);
    fruits.push_back({x, y});
}

unsigned int Game::StartGame(std::string name) {
    MSG msg;
    InitEvent();
    InitThread();
    GameWindow object_window;
    Snake object_snake;
    std::vector<Fruit> fruits;
    BOOL bRet;

    for (int i = 0; i < 5; i++) {
        NewFruit(fruits);
    }

    while (true) {
        system("cls");

        if ((bRet = PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) != 0) {

            if (msg.wParam == 27) {
                break;
            }

            switch (msg.wParam) {
            case 72: {
                object_snake.SetVector(1);
                break;
            }
            case 77: {
                object_snake.SetVector(2);
                break;
            }
            case 80: {
                object_snake.SetVector(3);
                break;
            }
            case 75: {
                object_snake.SetVector(0);
                break;
            }
            }
        }

        point place = object_snake.Move();

        if (object_window.Collision(place) || object_snake.Collision(place)) {
            break;
        }

        for (int i = 0; i < fruits.size(); i++) {
            if (fruits[i].Collision(place)) {
                object_snake.Add();
                fruits.erase(fruits.begin() + i);
                NewFruit(fruits);
                count++;
            }
        }

        for (int i = 0; i < fruits.size(); i++) {
            fruits[i].Set(hDC);
        }
        object_window.Set(hDC);
        object_snake.Set(hDC);
        std::cout << "\t\t\t\t\t\t\t\t\t Current count - " << count;
    }

    return count;
}