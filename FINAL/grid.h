#ifndef GRID_H
#define GRID_H
#include "creature.h"
#include "wall.h"
#include "predator.h"
#include "prey.h"

class Grid
{
    friend class Game;
public:
    ~Grid();
    Grid();
    Grid(int NumPrey,int NumPredator);
    void WallGenerator();//generate walls at the beginning
    void PreyGenerator();//generate preys at the beginning
    void PredatorGenerator();//generate predators at the beginning
    void move();//only function for user to use
    void show();//show the grid to console
    int count_cre(int crenum);//calculate the num of the prey or predator
    int count_Ecre(int crenum);//calculate the num of the evolved prey or predator
private:
    Creature* grid[MAX+1][MAX];
    int Prey_Alive;
    int E_Prey_Alive;
    int E_Predator_Alive;
    int Predator_Alive;
    int turn;
};

#endif // GRID_H
