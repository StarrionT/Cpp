#include "queen_prey.h"

Queen_Prey::Queen_Prey(){Evolved=1;}
Queen_Prey::Queen_Prey(int i,int j,int TURN,int STARVE,int FOOD,int OFF,int LAST_BREED,int LAST_EAT):Creature(i,j,prey)
{
    Evolved=1;
    turn=TURN;
    starve=STARVE;
    Food_Eaten=FOOD;
    Offspring=OFF;
    last_breed=LAST_BREED;
    last_eat=LAST_EAT;}

void Queen_Prey::move(Creature* grid[][MAX])
{
    enum direction{top=1,down=2,left=3,right=4};
    WalkAround(grid);
    breed(grid);
    Moved=1;
    turn++;
    die(grid);
}

void Queen_Prey::breed(Creature* grid[][MAX])
{
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(grid[row+i][col+j]==NULL)
            {
                grid[row+i][col+j]=new Prey(row+i,col+j);
                Offspring++;
                last_breed=turn+1;
            }
            else if(grid[row+i][col+j]->CreNum()==predator&&grid[row+i][col+j]->Evo_Stat()==0)
            {
//                srand(time(0));
                int chance=rand()%10;
                if(chance <2)
                {
                    if(grid[22][0]==grid[row+i][col+j])
                        grid[row+i][col+j]->Killed();
                    else
                    {
                        delete grid[row+i][col+j];

                    }
                    grid[row+i][col+j]=new Prey(row+i,col+j);
                    Offspring++;
                    last_breed=turn+1;
                }
            }
        }
    }

}

void Queen_Prey::WalkAround(Creature* grid[][MAX])
{
    enum direction{top=1,down=2,left=3,right=4};
    int CheckFull[4]={0,0,0,0};
//    srand(time(0));
    bool MoveDone=0;
    int Direction;
    int count=0;
    do
    {
        Direction= rand()%4+1;
        if (CheckFull[Direction-1]==0)
        {
            switch(Direction)
            {
            case (top):
                if(grid[row][col+1]==NULL)
                {
                    grid[row][col+1]=grid[row][col];
                    grid [row][col]=NULL;
                    col=col+1;
                    MoveDone=1;
                }
                break;
            case (down):
                if(grid[row][col-1]==NULL)
                {
                    grid[row][col-1]=  grid[row][col];
                    grid [row][col]=NULL;
                    col=col-1;
                    MoveDone=1;
                }
                break;
            case (left):
                if(grid[row-1][col]==NULL)
                {
                    grid[row-1][col]= grid[row][col];
                    grid [row][col]=NULL;
                    row=row-1;
                    MoveDone=1;
                }
                break;
            case (right):
                if(grid[row+1][col]==NULL)
                {
                    grid[row+1][col]= grid[row][col];
                    grid [row][col]=NULL;
                    row=row+1;
                    MoveDone=1;
                }
                break;
            }
            CheckFull[Direction-1]=1;
            count++;
        }
    }
    while((MoveDone==0)&&count<4);
}

void Queen_Prey::die(Creature* grid[][MAX])
{
    if(Offspring>=20)
    {
        int temp_x=row;
        int temp_y=col;
        if(grid[22][0]==grid[row][col])
        {
            grid[row][col]->Killed();
        }
        else
        {
            delete grid[row][col];
        }
        grid[temp_x][temp_y]=NULL;
    }
}
