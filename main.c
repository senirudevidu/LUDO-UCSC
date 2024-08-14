#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
#include "logic.c"

int main(){

    srand(time(0));
    
    intro();

    int first_player_index = firstPlayer();
    determineOrder(first_player_index);

    printf("\n");

    
    return 0;
    
 
}