//FILE NAME:FINAL
//LAST CHANGED:DEC 6.2014
//VERSION: UNRECORDED
//AUTHOR: SHEN TENG

//BRIEF INTRODUTION:
/*
 * FOUR CREATURES LIVING ON THE 20X20 GRID.
 * THEY PERFORM DIFFERENT WAYS OF MOVING.
 * PREY:
 *      MOVE IN 4 DIRECTIONS RANDOMLY AND 1 SQUARE EVERY TURN.
 *      BREED AT EVERY 3RD TURN.
 *      EVOLVE TO QUEEN AT 10 TH TURN AFTER BEING BORN.
 *      THE CHANCE OF EVOLVING IS 10%.
 * QUEEN:
 *      MOVE IN 4 DIRECTIONS RANDOMLY AND 1 SQUARE EVERY TURN.
 *      BREED UNTIL ALL THE SUQARE AROUND ITSELF IS FILLED.
 *      20% OF CHANCE CONVERT A UNEVOLVED PREDATOR INTO PREY.
 *      DIE AFTER BREEDING 20 PREYS.
 * PREDATOR:
 *      MOVE IN 4 DIRECTIONS RANDOMLY AND 1 SQUARE EVERY TURN.
 *      IF THERE ARE PREYS AROUND IT,
 *      IT WILL RANDOMLY MOVE ON THE SQUARE OF ONE OF THE PREYS AND EAT IT.
 *      DIE AFTER 3 TURNS WITHOUT ANY FOOD.
 *      BREED AT EVERY 8TH TURN.
 *      EVOLVE INTO HUNGER AT 3RD TURN.
 *      THE CHANCE OF EVOLVING IS 40%.
 * HUNGER:
 *      JUMP HORIZONTALLY OR VERTICALLY WITH RANDOM NUMBER OF SQUARES.
 *      EAT WHATEVER IT JUMPS ON. AND ALL CREATURES(EXCEPT QUEEN) AROUND IT AFTER JUMPING.
 *      DIE ATER EATING 20 CREATURES.
 *      AND IT WILL SPLIT INTO 4 PREDATOR AFTER DYING.
 */



#include <iostream>
#include <game.h>
int main()
{
    Game PP;
    PP.run();
    return 0;
}
