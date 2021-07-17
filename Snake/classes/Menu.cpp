#include "Menu.h"

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::StartMenu() {
    Game object_game;

    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    object_result.Add(name, object_game.StartGame(name));
    std::cout << std::endl << "Finish" << std::endl;
}

void Menu::ShowResult() {
    std::string str;
    std::cout << "Enter name or empty line: ";
    std::cin >> str;

    if (str == "") {
        std::cout << object_result.GetResults() << std::endl;
    }
    else {
        std::cout << object_result.GetResults(str) << std::endl;
    }
}

void Menu::MainMenu() {
    int exit(0);

    while (exit != 4) {
        system("cls");

        std::cout << "Menu" << std::endl;
        std::cout << "1 - Start" << std::endl;
        std::cout << "2 - Show result" << std::endl;
        std::cout << "3 - Demo" << std::endl;
        std::cout << "4 - Exit" << std::endl;
        std::cin >> exit;

        switch (exit) {
        case 1: {
            StartMenu();
            break;
        }
        case 2: {
            ShowResult();
            break;
        }
        case 3: {
            break;
        }
        }
    }
}