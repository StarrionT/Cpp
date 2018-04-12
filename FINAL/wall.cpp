#include "wall.h"
Wall::Wall(){}
Wall::Wall(int i,int j):Creature(i,j,wall)
{}
void Wall::move(Creature* grid[][MAX])
{
    cout<<"wall move should be called.\n";
}
