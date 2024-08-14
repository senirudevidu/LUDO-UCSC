#include "types.h"

void intro(){

    printf("The red player has 04 pieces named R1,R2,R3,R4\n");
    printf("The green player has 04 pieces named G1,G2,G3,G4\n");
    printf("The yellow player has 04 pieces named Y1,Y2,Y3,Y4\n");
    printf("The blue player has 04 pieces named B1,B2,B3,B4\n");
    
    printf("\n");
}

// Generates a random dice value between 1 and 6
int diceValue(int playerIndex){
    
    int dice_Value = rand() % 06 + 1;
    //printf("Player %d got %d\n", playerIndex + 1, dice_Value);
    return dice_Value; 
}

// Determines the first player based on the highest dice roll
int firstPlayer(){ 

    int firstRoundValues[4];

    for(int i = 0; i < 4; i++){
        firstRoundValues[i] = diceValue(i);
    }

    int max = 0;
    int maxIndex;

    for(int i = 0; i <4 ; i++){
        if(firstRoundValues[i] > max){
            max = firstRoundValues[i];
            maxIndex = i;
        }
    }

    // Printing the dice rolls for each player
    printf("Red rolls %d\n", firstRoundValues[0]);
    printf("Green rolls %d\n", firstRoundValues[1]);
    printf("Yellow rolls %d\n", firstRoundValues[2]);
    printf("Blue rolls %d\n", firstRoundValues[3]);

    printf("\n");


    // Determining the first player based on the highest dice roll
    switch (maxIndex)
    {
    case 0 : printf("Red player has the highest roll and will begin the game."); break;
    case 1 : printf("Green player has the highest roll and will begin the game."); break;
    case 2 : printf("Yellow player has the highest roll and will begin the game."); break;
    case 3 : printf("Blue player has the highest roll and will begin the game."); break;
    }

    printf("\n");

    return maxIndex;

}

const char* playerColor(int maxIndex) {
    switch (maxIndex) {
        case 0: return "Red"; break;
        case 1: return "Green"; break;
        case 2: return "Yellow"; break;
        case 3: return "Blue"; break;
        default: return "Unknown"; break;
    }
}

void determineOrder(int startIndex) {
    printf("The order of a single round is ");
    for (int i = 0; i < 4; i++) {  
        printf("%s ",playerColor((startIndex + i) % 4));
    } 
    printf(".\n");
}

