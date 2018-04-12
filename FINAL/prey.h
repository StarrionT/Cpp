#ifndef PREY_H
#define PREY_H
#include "creature.h"
#include "queen_prey.h"

class Prey :public Creature
{
public:
    virtual~Prey(){}
    Prey();
    Prey(int i,int j);
    virtual void move(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);
    void WalkAround(Creature* grid[][MAX]);
    void Evolve(Creature* grid[][MAX]);
};

#endif // PREY_H
