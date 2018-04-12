#include "creature.h"

Creature::Creature():row(0),col(0),CreatureNum(0),turn(0),starve(0),Food_Eaten(0),Offspring(0),
    last_breed(0),last_eat(0),
    Moved(1),Evolved(false),dead(false){}
Creature::Creature(int i,int j,int CreNum):
    row(i),col(j),CreatureNum(CreNum),turn(0),starve(0),Food_Eaten(0),Offspring(0),
    last_breed(0),last_eat(0),
    Moved(1),Evolved(false),dead(false){}
void Creature:: move(Creature* grid[][MAX])
{
    cout<<"creature move should be called.\n";
}

int Creature::CreNum()
{
    return CreatureNum;
}
void Creature:: OnOffhMoved()
{
    Moved=!Moved;
}
bool Creature:: AlreadyMoved()
{
    return Moved;
}
bool Creature::Evo_Stat()
{
    return Evolved;
}
