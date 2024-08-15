#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
#include "logic.c"

int main(){

    srand(time(0));
    
    intro();

    int startIndex = firstPlayer();
    determineOrder(startIndex);

    int currentPlayerIndex = firstPlayer();

    //game loop
    for (int round = 0; round < 10 ; round++){
        
        printf("Round %d", round);
        for(int i = 0 ; i< 4 ; i++){
        int roll = diceValue(currentPlayerIndex);
        diceRollMessage(currentPlayerIndex, roll);
        currentPlayerIndex = (currentPlayerIndex + 1) % 4;
        }
        printf("\n");
    }


    printf("\n");

    
    return 0;
    
 
}