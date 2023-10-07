#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include "Clasa.h"
#include "game_code.h"

void startGame() {
    std::cout << "Alright!!" << std::endl;
    int ok = 0, c;
    Character enemy("Enemy", 110, 60, 30, 10);
    Character emy("Emy", 100, 50, 20, 10);
    Character liviu("Liviu", 80, 30, 15, 5);
    Character andrei("Andrei", 70, 80, 35, 2);
    std::cout << "Select your character: Emy , Liviu , Andrei (1,2,3) :" << std::endl;
    do
    {
        std::cin >> c;
        switch (c)
        {
        case 1:
        {
            if (emy.getHealth() != 0)
            {
                emy.Attack(enemy);
                enemy.Attack(emy);
            }
            if (emy.getHealth() == 0) {
                std::cout << "Emy is kaput. Fmm Emy" << std::endl;
                PlaySound(TEXT("gay.wav"), NULL, SND_FILENAME | SND_SYNC);
            }
            break;
        }
        case 2:
        {
            if (liviu.getHealth() != 0)
            {
                liviu.Attack(enemy);
                enemy.Attack(liviu);
            }
            if (liviu.getHealth() == 0) {
                std::cout << "Liviu is ded. Bro thought he stood a chance " << std::endl;
                PlaySound(TEXT("squirrel.wav"), NULL, SND_FILENAME | SND_SYNC);
            }
            break;
        }
        case 3:
        {
            if (andrei.getHealth() != 0)
            {
                andrei.Attack(enemy);
                enemy.Attack(andrei);
            }
            if (andrei.getHealth() == 0) {
                std::cout << "F ;(" << std::endl;
                PlaySound(TEXT("yoda.wav"), NULL, SND_FILENAME | SND_SYNC);
            }
            break;
        }
        default:
        {
            std::cout << "De la 1 pana la 3";
            break;
        }
        }
    } while (enemy.getHealth() != 0);
    std::cout << "Bro is ded.\nCongratz";
    PlaySound(TEXT("god.wav"), NULL, SND_FILENAME | SND_SYNC);
}