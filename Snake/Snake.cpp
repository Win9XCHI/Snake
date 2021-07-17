// Snake.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

DWORD WINAPI Listener(PVOID pvParam) {

    while (true) {
        PostThreadMessage(*(DWORD*)pvParam, WM_CHAR, _getch(), 0);
    }
    
    return 0;
}

int Game(string name) {
    MSG msg;
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
    }

    return 0;
}

int main() {
    int exit(0);

    while (exit != 4) {
        cout << "Menu" << endl;
        cout << "1 - Start" << endl;
        cout << "2 - Show result" << endl;
        cout << "3 - Demo" << endl;
        cout << "4 - Exit" << endl;
        cin >> exit;

        switch (exit) {
        case 1: {
            string name = "1";
            //cout << "Enter name";
            //cin >> name;
            int result = Game(name);
            cout << endl << "Finish";
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        }
    }

    return 0;
}


