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

for (int i = 0; i < 10; i++) {

    printf("__________Round %d___________\n", i);
    for(int j = 0; j <4; j++) {
        // Roll the dice
        int roll = diceValue();
        diceRollMessage(currentPlayerIndex, roll);

        Player* currentPlayer;
        int* currentPath;
        int homeStraightIndex;
        
        switch (currentPlayerIndex) {
            case 0:
                currentPlayer = &redPlayer;
                currentPath = redPath;
                homeStraightIndex = 52;
                break;
            case 1:
                currentPlayer = &greenPlayer;
                currentPath = greenPath;
                homeStraightIndex = 57;
                break;
            case 2:
                currentPlayer = &yellowPlayer;
                currentPath = yellowPath;
                homeStraightIndex = 62;
                break;
            case 3:
                currentPlayer = &bluePlayer;
                currentPath = bluePath;
                homeStraightIndex = 67;
                break;
            default:
                printf("Error: Invalid player index.\n");
                break;
        }

        // Move one piece based on some logic (here, move the first valid piece)
        for (int j = 0; j < 4; j++) {
            if (currentPlayer->pieces[j].isInPlay || (roll == 6 && currentPlayer->pieces[j].position == BASE)) {
                movePlayer(&currentPlayer->pieces[j], currentPlayer, roll, currentPath, TOTAL_RUNNING_CELLS, homeStraightIndex);
                break;  // Move only one piece per turn
            }
        }

        // If the roll was not 6, move to the next player
        if (roll != 6) {
            currentPlayerIndex = (currentPlayerIndex + 1) % 4;
        }
        
        printf("\n");
    }
}
    return 0;
}