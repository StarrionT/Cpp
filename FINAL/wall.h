#ifndef WALL_H
#define WALL_H
#include "creature.h"
class Wall :public Creature
{
public:
    Wall();
    Wall(int i, int j);
    virtual void move(Creature* grid[][MAX]);
};

#endif // WALL_H
