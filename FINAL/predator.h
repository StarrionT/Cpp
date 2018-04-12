#ifndef PREDATOR_H
#define PREDATOR_H
#include "creature.h"
#include "hunger_predator.h"
class Predator :public Creature
{
public:
     ~Predator(){}
    Predator();
    Predator(int i,int j);
    virtual void move(Creature* grid[][MAX]);
    int SearchAdj(Creature* grid[][MAX],int CheckFull[]);//function used to check the squares in 4 directions
    void Eat(int Move, Creature *grid[][MAX]);//function to eat
    void WalkAround(int CheckFull[],Creature* grid[][MAX]);//moving on the grid
    void die(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);
    void Evolve(Creature* grid[][MAX]);
};

#endif // PREDATOR_H
