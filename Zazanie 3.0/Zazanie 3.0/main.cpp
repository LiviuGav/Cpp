#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include "Clasa.h"
#include "game_code.h"
#include <conio.h>

#pragma comment(lib,"winmm.lib")

void printMenu(int highlight) {
    system("cls"); 

    std::cout << "Welcome" << std::endl;
    std::cout << (highlight == 0 ? "> " : "  ") << "Play" << std::endl; // ? - if
    std::cout << (highlight == 1 ? "> " : "  ") << "Exit" << std::endl; // : - else
}

int main() {
    int choice = 0;
    int highlight = 0;

    do {
        printMenu(highlight);

        while (true) {
            choice = _getch();
            if (choice == 224) 
                choice = _getch();

            switch (choice) {
            case 72: 
                highlight = (highlight - 1 + 2) % 2;
                break;
            case 80: 
                highlight = (highlight + 1) % 2;
                break;
            case 13: 
                if (highlight == 0) {
                    startGame();
                    _getch(); 
                }
                else if (highlight == 1) {
                    std::cout << "Bye" << std::endl;
                    return 0;
                }
                break;
            }
            break;
        }
    } while (true);

    return 0;
}

