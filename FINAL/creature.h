#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <ctime>
#include<cstdlib>

using namespace std;
const int MAX=22;
enum creature_number
{
    wall=0,prey=1,predator=2
};

class Creature
{
    friend class Game;
public:
    virtual~Creature(){}
    Creature();
    Creature(int i, int j, int CreNum);
    virtual void move(Creature* grid[][MAX]);
    int CreNum();//return crenum
    void OnOffhMoved();//switch bool of moved
    void Killed(){dead=1;}//make dead=1
    bool AlreadyMoved();//return moved boolean
    bool Evo_Stat();//return bool of evolving
protected:
    int row;
    int col;
    int CreatureNum;
    int turn;
    int starve;
    int Food_Eaten;
    int Offspring;
    int last_breed;
    int last_eat;
    bool Moved;
    bool Evolved;
    bool dead;
};

#endif // CREATURE_H
