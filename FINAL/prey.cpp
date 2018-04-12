#include "prey.h"
Prey::Prey(){}
Prey::Prey(int i,int j):Creature(i,j,prey)
{}
void Prey::move(Creature* grid[][MAX])
{
    enum direction{top=1,down=2,left=3,right=4};
    WalkAround(grid);
    turn=turn+1;
    if(turn%3==0&&turn>0)
        breed(grid);
    Moved=1;
    Evolve(grid);
}
void Prey::breed(Creature* grid[][MAX])
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
                    grid[row][col+1]=new Prey(row,col+1);
                    Offspring++;
                    last_breed=turn;
                    MoveDone=1;
                }
                break;
            case (down):
                if(grid[row][col-1]==NULL)
                {
                    grid[row][col-1]=new Prey(row,col-1);
                    Offspring++;
                    last_breed=turn;

                    MoveDone=1;
                }

                break;
            case (left):
                if(grid[row-1][col]==NULL)
                {
                    grid[row-1][col]= new Prey(row-1,col);
                    Offspring++;
                    last_breed=turn;
                    MoveDone=1;
                }
                break;
            case (right):
                if(grid[row+1][col]==NULL)
                {
                    grid[row+1][col]= new Prey(row+1,col);
                    Offspring++;
                    last_breed=turn;
                    MoveDone=1;
                }
                break;
            }
            CheckFull[Direction-1]=1;
        }
        count++;
    }
    while(!MoveDone&&count<4);
}
void Prey::WalkAround(Creature* grid[][MAX])
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
void Prey::Evolve(Creature *grid[][MAX])
{
    if(turn==10)
    {
//        srand (time(NULL));
        int chance=rand()%100+1;
        if (chance<=10)
        {
            int temp_x=row;
            int temp_y=col;
            bool getpointed=0;
            if(grid[row][col]==grid[22][0])
            {
                getpointed=1;
            }
            delete grid[row][col];
            grid[temp_x][temp_y]=new Queen_Prey(temp_x,temp_y,turn,starve,Food_Eaten,Offspring,last_breed,last_eat);

            if(getpointed)
                grid[22][0]=grid[temp_x][temp_y];

        }
    }
}
