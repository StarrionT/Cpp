#include "predator.h"

Predator::Predator(){}
Predator::Predator(int i, int j): Creature(i,j,predator){}
void Predator::move(Creature* grid[][MAX])
{
    Moved=1;
    int Move;
    int CheckFull[4]={0,0,0,0};
    Move=SearchAdj(grid,CheckFull);
    if(Move>=0&&Move<=3)//eat
    {
        Eat(Move,grid);
        Food_Eaten++;
        last_eat=turn;
        starve=0;
    }
    else if (Move==-1)
    {
        starve++;
    }
    else
    {
        WalkAround(CheckFull,grid);
        starve++;
    }
    turn++;
    try
    {
    if (starve==3)
        throw 'D';
    if(turn%8==0&&turn>0)
    {
        breed(grid);
        last_breed=turn;
    }
    if(turn==3)
        throw 1;
    }
    catch (char){
        die(grid);
    }
    catch (int)
    {
        Evolve(grid);
    }
}
int Predator::SearchAdj(Creature *grid[][MAX],int CheckFull[]) //return-1 if top left right down are full; return 0,1,2,3 for position of the prey
{
    enum direction{top=1,down=2,left=3,right=4};
    int temp=100;
    bool Full=1;
    if(grid[row][col+1]==NULL)
        CheckFull[top-1]=0;
    else if(grid[row][col+1]->CreNum()==prey)
        CheckFull[top-1]=1;
    else
        CheckFull[top-1]=2;

    if(grid[row][col-1]==NULL)
        CheckFull[down-1]=0;
    else if(grid[row][col-1]->CreNum()==prey)
        CheckFull[down-1]=1;
    else
        CheckFull[down-1]=2;

    if(grid[row+1][col]==NULL)
        CheckFull[right-1]=0;
    else if(grid[row+1][col]->CreNum()==prey)
        CheckFull[right-1]=1;
    else
        CheckFull[right-1]=2;

    if(grid[row-1][col]==NULL)
        CheckFull[left-1]=0;
    else if(grid[row-1][col]->CreNum()==prey)
        CheckFull[left-1]=1;
    else
        CheckFull[left-1]=2;

    for (int count =0;count <4;count++)
    {
        if (CheckFull[count]==0)
        {
            Full=0;
            break;
        }
    }

//    srand(time(0));
    int Rand= rand()%4;
    int rand_record[4]={0,0,0,0};
    bool s=0;
    while(s==0)
    {
        Rand= rand()%4;
        s=1;
        if(CheckFull[Rand]==1)
            return Rand;
        else
        {
            rand_record[Rand]=1;
        }
        for(int count=0;count<4;count++)
        {
            if(rand_record[count]==0)
            {
                s=0;
            }
        }
    }

    if(Full)
        temp=-1;
    return temp;

//    for (int count =0;count <4;count++)
//    {
//        if(CheckFull[count]==1)
//        {
//            temp=count;
//            return temp;
//        }
//        if (CheckFull[count]==0)
//        {
//            Full=0;
//            break;
//        }
//    }
//    if(Full)
//        temp=-1;
//    return temp;
}
void Predator::Eat(int Move,Creature* grid[][MAX])
{
    enum direction{top=1,down=2,left=3,right=4};

    switch (Move+1)
    {

    case top:
        if(grid[22][0]==grid[row][col+1])
            grid[22][0]->Killed();
        else
        {
            delete grid[row][col+1];
        }
        grid[row][col+1]=grid[row][col];
        grid[row][col]=NULL;
        col=col+1;
        break;
    case down:
        if(grid[22][0]==grid[row][col-1])
            grid[22][0]->Killed();
        else
        {
            delete grid[row][col-1];
        }
        grid[row][col-1]=grid[row][col];
        grid[row][col]=NULL;
        col=col-1;
        break;
    case left:
        if(grid[22][0]==grid[row-1][col])
            grid[22][0]->Killed();
        else
        {
            delete grid[row-1][col];
        }
        grid[row-1][col]=grid[row][col];
        grid[row][col]=NULL;
        row=row-1;
        break;
    case right:
        if(grid[22][0]==grid[row+1][col])
            grid[22][0]->Killed();
        else
        {
            delete grid[row+1][col];
        }
        grid[row+1][col]=grid[row][col];
        grid[row][col]=NULL;
        row=row+1;
        break;
    }
}
void Predator:: WalkAround(int CheckFull[],Creature* grid[][MAX])
{
    enum direction{top=1,down=2,left=3,right=4};
//    srand(time(NULL));
    bool MoveDone=0;
    int Direction;

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
        }
    }
    while(!MoveDone);
}
void Predator::die(Creature* grid[][MAX])
{
    int temp_x=row;
    int temp_y=col;
    delete grid[row][col];
    grid[temp_x][temp_y]=NULL;
}
void Predator::breed(Creature* grid[][MAX])
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
                    grid[row][col+1]=new Predator(row,col+1);
                    MoveDone=1;
                }
                break;
            case (down):
                if(grid[row][col-1]==NULL)
                {
                    grid[row][col-1]=new Predator(row,col-1);
                    MoveDone=1;
                }

                break;
            case (left):
                if(grid[row-1][col]==NULL)
                {
                    grid[row-1][col]= new Predator(row-1,col);
                    MoveDone=1;
                }
                break;
            case (right):
                if(grid[row+1][col]==NULL)
                {
                    grid[row+1][col]= new Predator(row+1,col);
                    MoveDone=1;
                }
                break;
            }
            CheckFull[Direction-1]=1;
            count++;
        }
    }
    while(!MoveDone&&count<4);
}

void Predator::Evolve(Creature *grid[][MAX])
{
    bool getpointed=0;
//    if(turn==3)
    {
//        srand (time(NULL));
        int chance=rand()%10;
        if (chance<=3)
        {
            int temp_x=row;
            int temp_y=col;
            if(grid[22][0]==grid[row][col])
            {
                getpointed=1;
            }

            delete grid[row][col];
            grid[temp_x][temp_y]=new Hunger_Predator(temp_x,temp_y,turn,starve,Food_Eaten,Offspring,last_breed,last_eat);

            if(getpointed)
            {
                grid[22][0]=grid[temp_x][temp_y];
            }

//            cout << "tempx "<<temp_x<<endl;
//            cout << "tempy "<<temp_y<<endl;
        }
    }
}
