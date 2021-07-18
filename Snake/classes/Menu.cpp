#include "Menu.h"

Menu::Menu() {

}

Menu::~Menu() {

}

/* Game
 * Input: -
 * Output: -	 */
void Menu::StartMenu() {
    Game object_game;

    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    try {
        unsigned int result = object_game.StartGame(name);
        object_result.Add(name, result);
        std::cout << std::endl << "Your result - " << result << std::endl;
    }
    catch (KernelObjectException object) {
        system("cls");
        std::cout << std::endl << "\tError game: " << object.what() << std::endl;
    }

    Sleep(10000);
}

/* Show result
 * Input: -
 * Output: -	 */
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

/* Main menu
 * Input: -
 * Output: -	 */
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