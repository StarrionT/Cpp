#include "hunger_predator.h"

Hunger_Predator::Hunger_Predator()
{
    Evolved=1;
}
Hunger_Predator::Hunger_Predator(int i, int j,int TURN,int STARVE,int FOOD,int OFF,int LAST_BREED,int LAST_EAT): Creature(i,j,predator)
{
    Evolved=1;
    turn=TURN;
    starve=STARVE;
    Food_Eaten=FOOD;
    Offspring=OFF;
    last_breed=LAST_BREED;
    last_eat=LAST_EAT;
}

void Hunger_Predator::move(Creature* grid[][MAX])
{

    WalkAroud(grid);
    eat(grid);
    Moved=1;
    turn++;
    if(Food_Eaten>=20)
        die(grid);
}

void Hunger_Predator::die(Creature* grid[][MAX])
{
    int temp_x=row;
    int temp_y=col;
    Creature* temp=grid[row][col];

    grid[row][col]=NULL;

    spwan(grid,temp_x,temp_y);
    spwan(grid,temp_x,temp_y);
    spwan(grid,temp_x,temp_y);
    spwan(grid,temp_x,temp_y);

    if (grid[22][0]==temp)
    {
        dead=1;
    }
    else
    {
        delete temp;
    }
}
void Hunger_Predator::spwan(Creature *grid[][MAX],int temp_x,int temp_y)
{
//    srand(time(0));
    int Spwan_Pos_x,Spwan_Pos_y;

    int count=0;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(grid[temp_x+i][temp_y+j]==NULL)
            {
                count ++;
            }
        }
    }
//    cout <<"count "<<count<<endl;
    if (count>0)
    {
        bool MoveDone=0;
        do
        {
            Spwan_Pos_x=rand()%3-1;
            Spwan_Pos_y=rand()%3-1;
            if(grid[temp_x+Spwan_Pos_x][temp_y+Spwan_Pos_y]==NULL)
            {
                grid[temp_x+Spwan_Pos_x][temp_y+Spwan_Pos_y]=
                        new Predator((temp_x+Spwan_Pos_x),(temp_y+Spwan_Pos_y));
                MoveDone=1;
            }
        }while(MoveDone==0);
    }
}
void Hunger_Predator::eat(Creature* grid[][MAX])
{
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {


//            cout<<"row+i: "<<row+i<<endl;
//            cout<<"col+j: "<<col+j<<endl;

            try
            {
                if(i==0&&j==0)
                    throw 1;
                if(grid[row+i][col+j]!=NULL)
                {
//                                cout<<"row: "<<row<<endl;
//                                cout<<"col: "<<col<<endl;
                    if(grid[row+i][col+j]->CreNum()!=wall)
                    {
                        if(!(grid[row+i][col+j]->Evo_Stat()==1&&grid[row+i][col+j]->CreNum()==prey))
                        {
                            if(grid[22][0]==grid[row+i][col+j])
                            {
                                grid[row+i][col+j]->Killed();
                            }
                            else
                            {
                                delete grid[row+i][col+j];
                            }
                            grid[row+i][col+j]=NULL;
                            Food_Eaten++;
                            last_eat=turn;
                        }
                    }
                }
            }
            catch( int)
            {
                //do nothing
            }
        }
    }
}
void Hunger_Predator::WalkAroud(Creature* grid[][MAX])
{
    int direction;
//    srand(time(0));
    direction=rand()%2+1;
    if(direction==1)
    {
        int position=col;
        do
        {
            position=rand()%20+1;
//            cout <<"Position" <<position<<endl;
        }
        while(position==col);
        if(grid[row][position]!=NULL)
        {
            if(grid[22][0]==grid[row][position])
            {
                grid[row][position]->Killed();
            }
            else
            {
                delete grid[row][position];
            }
            Food_Eaten++;
            last_eat=turn;
        }
        grid[row][position]=grid[row][col];
        grid[row][col]=NULL;
        col=position;
    }
    else if (direction==2)
    {
        int position=row;
        do
        {
            position=rand()%20+1;
        }
        while(position==row);
        if(grid[position][col]!=NULL)
        {
            if(grid[position][col]==grid[22][0])
            {
                grid[position][col]->Killed();
            }
            else
            {
                delete grid[position][col];
            }
            Food_Eaten++;
            last_eat=turn;
        }
        grid[position][col]=grid[row][col];
        grid[row][col]=NULL;
        row=position;
    }
}
