#ifndef QUEEN_PREY_H
#define QUEEN_PREY_H
#include "creature.h"
#include "prey.h"
/*queen:
 * evolved from prey at 10th turn, 10% chance
 * breed until all the squares around it are filled
 * 20% chance convert normal predator creature in to prey
 * die after breeding 20 offsrpings
 */
class Queen_Prey:public Creature
{
public:
    virtual ~Queen_Prey(){}
    Queen_Prey();
    Queen_Prey(int i, int j, int TURN, int STARVE, int FOOD, int OFF, int LAST_BREED, int LAST_EAT);
    virtual void move(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);
    void WalkAround(Creature* grid[][MAX]);//moving on the grid
    void die(Creature* grid[][MAX]);
};

#endif // QUEEN_PREY_H
