#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "types.h"
#include "logic.h"

int main(){

    srand(time(0));
    
    intro();

    int startIndex = firstPlayer();
    determineOrder(startIndex);

    int currentPlayerIndex = firstPlayer();
    Piece playerPieces[4];

    for (int i = 0; i < 4; i++)
    {
        playerPieces[i].position = -1;
        playerPieces[i].isInPlay = 0;
    }
    

    //game loop
    for (int round = 0; round < 10 ; round++){
        
        printf("Round %d\n", round);
        for(int i = 0 ; i< 4 ; i++){
            int roll = diceValue(currentPlayerIndex);
            diceRollMessage(currentPlayerIndex, roll);

            movePieceOut(&playerPieces[currentPlayerIndex], roll);

            currentPlayerIndex = (currentPlayerIndex + 1) % 4;
        }
        printf("\n");
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Piece %d is in %d\n", i, playerPieces[i].position);
    }
    

    printf("\n");

    
    return 0;
    
 
}