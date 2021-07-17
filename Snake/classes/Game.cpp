#include "Game.h"

Game::Game() : count(0) {

}

Game::~Game() {

}

DWORD WINAPI Listener(PVOID pvParam) {

    while (true) {
        PostThreadMessage(*(DWORD*)pvParam, WM_CHAR, _getch(), 0);
    }

    return 0;
}

unsigned int Game::StartGame(std::string name) {
    system("cls");

    POINT op;
    HWND hWnd = GetConsoleWindow(); //Get descriptor consol window 
    HDC hDC = GetDC(hWnd); //Get context for descriptor
    //SelectObject(hDC, GetStockObject(BLACK_PEN)); //Choose pen BLACK_PEN

    MoveToEx(hDC, 50, 50, &op); //Set point
    LineTo(hDC, 100, 200); //Set line

    ReleaseDC(hWnd, hDC); //Free context

    /*MSG msg;
    HANDLE hThread;
    DWORD thread_id = GetCurrentThreadId();
    hThread = CreateThread(NULL, 0, Listener, &thread_id, 0, NULL);

    if (hThread == NULL) {
        throw "Error";
    }

    while (GetMessage(&msg, 0, 0, 0))
    {
        if (msg.wParam == 27) {
            CloseHandle(hThread);
            break;
        }
    }*/
    return 0;
}