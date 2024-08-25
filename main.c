#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "types.h"
#include "logic.h"

int main(){

    srand(time(0));
    
    intro();

    int currentPlayerIndex = firstPlayer();
    determineOrder(currentPlayerIndex);

    Player redPlayer = {{{BASE, 0}, {BASE, 0}, {BASE, 0}, {BASE, 0}}, 'R' , 0};
    Player greenPlayer = {{{BASE, 0}, {BASE, 0}, {BASE, 0}, {BASE, 0}}, 'G', 1};
    Player yellowPlayer = {{{BASE, 0}, {BASE, 0}, {BASE, 0}, {BASE, 0}}, 'Y', 2};
    Player bluePlayer = {{{BASE, 0}, {BASE, 0}, {BASE, 0}, {BASE, 0}}, 'B', 3};


    int redPath[TOTAL_RUNNING_CELLS] = {
        // Standerd Cells
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        // Home Straight
        52, 53, 54, 55, 56,
        // Homwe
        72
    };

    int greenPath[TOTAL_RUNNING_CELLS] = {
        // Standerd Cells
        13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 
        49, 50, 51, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        //Home Straight
        57, 58, 59, 60, 61,
        //Home
        72
    };

    int yellowPath[TOTAL_RUNNING_CELLS] = {
        // Standerd Cells
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
        //Home Straight
        62, 63, 64, 65, 66,
        //Home
        72
    };

    int bluePath[TOTAL_RUNNING_CELLS] = {
        // Standerd Cells
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 
        //Home Straight
        67, 68, 69, 70, 71, 
        //Home
        72

    };

    for (int i = 0; i < 16; i++)
    {
            //roll the dice
            int roll = diceValue();
            //print the dice value and current player
            diceRollMessage(currentPlayerIndex, roll);
            
            //move the player
            switch (currentPlayerIndex) { 
                case 0:
                    movePlayer(&redPlayer.pieces[0], &redPlayer, roll, redPath, TOTAL_RUNNING_CELLS, 52);
                    break;
                case 1:
                    movePlayer(&greenPlayer.pieces[0], &greenPlayer, roll, greenPath, TOTAL_RUNNING_CELLS, 57);
                    break;
                case 2:
                    movePlayer(&yellowPlayer.pieces[0], &yellowPlayer, roll, yellowPath, TOTAL_RUNNING_CELLS, 62);
                    break;
                case 3:
                    movePlayer(&bluePlayer.pieces[0], &bluePlayer, roll, bluePath, TOTAL_RUNNING_CELLS, 67);
                    break;
                default:
                    printf("error\n");
                    break;
            }
            // If the roll was not 6, move to the next player
        if (roll != 6) {
            currentPlayerIndex = (currentPlayerIndex + 1) % 4;
        }
    
    printf("\n");
    return 0;
    }
}
