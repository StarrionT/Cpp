#ifndef HUNGER_PREDATOR_H
#define HUNGER_PREDATOR_H
#include "creature.h"
#include "predator.h"
/*Hunger:
 * evolved from predator at 3th turn,40% chance
 * eat 9 squares(everything except Queen), can jump to any spot on the straight line(Jumping will eat Queen though)
 * split into 4 predators after eating 20 creatures
 */
class Hunger_Predator: public Creature
{
public:
    ~Hunger_Predator(){}
    Hunger_Predator();
    Hunger_Predator(int i,int j,int TURN,int STARVE,int FOOD,int OFF,int LAST_BREED,int LAST_EAT);
    virtual void move(Creature* grid[][MAX]);
    void die(Creature* grid[][MAX]);
    void eat(Creature* grid[][MAX]);
    void WalkAroud(Creature* grid[][MAX]);//move on the grid
    void spwan(Creature* grid[][MAX], int temp_x, int temp_y);//split into 4 little predators
    //is actually called "spawn".. called when it dies
};

#endif // HUNGER_PREDATOR_H
