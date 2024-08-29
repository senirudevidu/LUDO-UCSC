#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "logic.h"

void intro()
{

    printf("The red player has 04 pieces named R1,R2,R3,R4\n");
    printf("The green player has 04 pieces named G1,G2,G3,G4\n");
    printf("The yellow player has 04 pieces named Y1,Y2,Y3,Y4\n");
    printf("The blue player has 04 pieces named B1,B2,B3,B4\n");

    printf("\n");
}

// Generates a random dice value between 1 and 6
int diceValue(){
    return rand() % 6 + 1;
}

// Determines the first player based on the highest dice roll
int firstPlayer()
{
    //dice rolled by all 4 players and store their respective dice values
    int firstRoundValues[4];
    for (int i = 0; i < 4; i++)
    {
        firstRoundValues[i] = diceValue();
    }
    
    // Printing the dice rolls for each player
    printf("Red rolls %d\n", firstRoundValues[0]);
    printf("Green rolls %d\n", firstRoundValues[1]);
    printf("Yellow rolls %d\n", firstRoundValues[2]);
    printf("Blue rolls %d\n", firstRoundValues[3]);

    printf("\n");

    int max = 0;
    int maxIndex;

    for (int i = 0; i < 4; i++)
    {
        if (firstRoundValues[i] > max)
        {
            max = firstRoundValues[i];
            maxIndex = i;
        }
    }


    // print the first player based on the highest dice roll
    switch (maxIndex)
    {
    case 0:
        printf("Red player has the highest roll and will begin the game.\n");
        break;
    case 1:
        printf("Green player has the highest roll and will begin the game.\n");
        break;
    case 2:
        printf("Yellow player has the highest roll and will begin the game.\n");
        break;
    case 3:
        printf("Blue player has the highest roll and will begin the game.\n");
        break;
    }

    printf("\n");
    

    return maxIndex;
}

const char *playerColor(int playerIndex)
{
    switch (playerIndex)
    {
    case 0:
        return "Red";
        break;
    case 1:
        return "Green";
        break;
    case 2:
        return "Yellow";
        break;
    case 3:
        return "Blue";
        break;
    default:
        return "Unknown";
        break;
    }
}

void determineOrder(int startIndex)
{
    printf("The order of a single round is ");
    for (int i = 0; i < 4; i++)
    {
        printf("%s ", playerColor((startIndex + i) % 4));
    }
    printf(".\n");
}

// once a dice rolled the following message should be output
void diceRollMessage(int playerIndex, int roll)
{
    printf("%s player rolled %d\n", playerColor(playerIndex), roll);
    
}
 

void rollSeveralTimes(Piece* pieces) {
    int totalMove = 0;
    int rollCount = 0;

    while (rollCount < 3) {
        int roll = diceValue();  // Get the dice roll value
        if (roll == 6) {
            totalMove += roll;
            rollCount++;
        } else {
            totalMove += roll;
            break;  // Exit loop since the roll is not a 6
        }
    }

    // Check if three consecutive sixes were rolled
    if (rollCount == 3) {
        // Ignore the move and hand over the dice to the next player
        return;
    }

    // Move the piece by the totalMove
    pieces->position += totalMove;

    // Hand over the dice to the next player
}

void howManyPieces(Player *players){
    int inPlayCount = 0, inBaseCount = 0;
        for (int i = 0; i < TOTAL_PIECES; i++) {
            if (players->pieces[i].isInPlay) {
                inPlayCount++;
            } else {
                inBaseCount++;
            }
        }

         printf("%s player now has %d/4 pieces on the board and %d/4 pieces in the base.\n",
               playerColor(players->index), inPlayCount, inBaseCount);
}

void movePlayer(Piece *pieces, Player *players, int diceValue, int path[], int totalRunningCells, int homestraightIndex) {
    // Logic to move a piece from base to start square 'X'
    if (diceValue == 6 && pieces->position == BASE) {
        pieces->position = path[START_X];  // Move piece to the starting square
        pieces->isInPlay = 1;  // Mark the piece as active on the board

        printf("%s player moves piece %c%d to the starting point.\n", 
               playerColor(players->index), players->colour, (int)(pieces - players->pieces) + 1);
        
        howManyPieces(players);  // Additional functionality to count active pieces
        rollSeveralTimes(pieces);  // Player rolls again if they rolled a 6
        return;
    }

    // Logic for moving an active piece
    if (pieces->isInPlay == 1) {
        int currentPositionIndex = pieces->position;
        int newPositionIndex = currentPositionIndex + diceValue;

        // Standard cells movement
        if (currentPositionIndex < homestraightIndex) {
            if (newPositionIndex < homestraightIndex) {
                // Normal movement within standard cells
                printf("%s player moves piece %c%d from location %d to %d by %d.\n",
                       playerColor(players->index), players->colour, (int)(pieces - players->pieces) + 1,
                       currentPositionIndex, newPositionIndex, diceValue);
                pieces->position = newPositionIndex;
            } else {
                // Move into home straight
                int homeStraightPos = homestraightIndex + (newPositionIndex - homestraightIndex);
                printf("%s player moves piece %c%d from location %d to %d by %d.\n",
                       playerColor(players->index), players->colour, (int)(pieces - players->pieces) + 1,
                       currentPositionIndex, homeStraightPos, diceValue);
                pieces->position = homeStraightPos;
            }

            // If the player rolls a 6, they get another turn
            if (diceValue == 6) {
                rollSeveralTimes(pieces);
            }
        }
        // Home straight movement
        else if (currentPositionIndex >= homestraightIndex && currentPositionIndex < totalRunningCells) {
            int toHome = totalRunningCells - currentPositionIndex - 1;

            if (diceValue == toHome) {
                // Exact roll to reach home
                pieces->position = totalRunningCells - 1;
                pieces->isInPlay = 0;  // Mark piece as home
                printf("%s player moves piece %c%d to home.\n",
                       playerColor(players->index), players->colour, (int)(pieces - players->pieces) + 1);
                // Add any winning logic here if required
            } else if (diceValue < toHome) {
                // Move within the home straight
                printf("%s player moves piece %c%d from location %d to %d by %d.\n",
                       playerColor(players->index), players->colour, (int)(pieces - players->pieces) + 1,
                       currentPositionIndex, newPositionIndex, diceValue);
                pieces->position = newPositionIndex;
            } else {
                // Overshoot - No movement allowed, hand over the turn to the next player
                printf("%s player cannot move piece %c%d due to overshoot.\n",
                       playerColor(players->index), players->colour, (int)(pieces - players->pieces) + 1);
            }

            // If the player rolls a 6, they get another turn
            if (diceValue == 6) {
                rollSeveralTimes(pieces);
            }
        }
    }
}
