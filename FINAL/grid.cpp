#include "grid.h"
Grid::~Grid()
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            if(grid[i][j]!=NULL)
                delete grid[i][j];
        }
    }
}
Grid::Grid()
{
    for(int i=0; i<MAX+1;i++)
    {
        for (int j=0;j<MAX;j++)
        {
            grid[i][j]=NULL;
        }
    }
    WallGenerator();
    Predator_Alive=0;
    E_Prey_Alive=0;
    E_Predator_Alive=0;
    Prey_Alive=0;
    turn=0;
}
Grid::Grid(int NumPrey,int NumPredator)
{
    for(int i=0; i<MAX+1;i++)
    {
        for (int j=0;j<MAX;j++)
        {
            grid[i][j]=NULL;
        }
    }

    WallGenerator();

    for(int i=0;i<NumPrey;i++)
    {PreyGenerator();}
    for(int i=0;i<NumPredator;i++)
    {PredatorGenerator();}
    Predator_Alive=NumPredator;
    Prey_Alive=NumPrey;
    E_Prey_Alive=0;
    E_Predator_Alive=0;
    turn=0;
}

void Grid::move()
{
    if (turn==0)
    {
        for(int i=0; i<MAX;i++)
        {
            for (int j=0;j<MAX;j++)
            {
                if(grid[i][j]!=NULL)
                    grid[i][j]->OnOffhMoved();
            }
        }
    }

    for(int i=0; i<MAX;i++)
    {
        for (int j=0;j<MAX;j++)
        {
            if(grid[i][j]!=NULL&&grid[i][j]->AlreadyMoved()==0)
            {
                if(grid[i][j]->CreNum()==2)
                {
                    grid[i][j]->move(grid);
                }
            }
        }
    }
    for(int i=0; i<MAX;i++)
    {
        for (int j=0;j<MAX;j++)
        {
            if(grid[i][j]!=NULL&&grid[i][j]->AlreadyMoved()==0)
            {
                if(grid[i][j]->CreNum()==1)
                {
                    grid[i][j]->move(grid);
                }
            }
        }
    }
    for(int i=0; i<MAX;i++)
    {
        for (int j=0;j<MAX;j++)
        {
            if(grid[i][j]!=NULL)
                grid[i][j]->OnOffhMoved();
        }
    }
    Prey_Alive=count_cre(1);
    Predator_Alive=count_cre(2);
    E_Predator_Alive=count_Ecre(2);
    E_Prey_Alive=count_Ecre(1);
    turn++;
}
void Grid::WallGenerator()
{
    for(int i=0;i<MAX;i++)
    {
        grid[i][0]=new Wall(i,0);
        grid[i][MAX-1]=new Wall(i,MAX-1);
    }
    for(int j=1;j<MAX;j++)
    {
        grid[0][j]=new Wall(0,j);
        grid[MAX-1][j]=new Wall(MAX-1,j);
    }
}
void Grid::PreyGenerator()
{
//    srand(time(0));
    bool stop=0;
    do
    {
        int row=rand()% (MAX-2)+1;
        int col=rand()% (MAX-2)+1;
        if (grid[row][col]==NULL)
        {
            grid[row][col]=new Prey(row,col);
            stop=1;
        }
    }
    while (stop!=1);
}
void Grid::PredatorGenerator()
{

//    srand(time(0));
    bool stop=0;
    do
    {
        int row=rand()% (MAX-2)+1;
        int col=rand()% (MAX-2)+1;
        if (grid[row][col]==NULL)
        {
            grid[row][col]=new Predator(row,col);
            stop=1;
        }
    }
    while (stop!=1);
}
void Grid::show()
{

    cout<<"turn:"<<turn<<endl;
    for(int i=0; i<MAX;i++)
    {
        for (int j=0;j<MAX;j++)
        {
            if(grid[i][j]!=NULL)
            {
                if(grid[i][j]->CreNum()==0)
                {
                    cout<<"* ";
                }
                if(grid[i][j]->CreNum()==1)
                {
                    if(grid[i][j]->Evo_Stat()==0)
                        cout<<"o ";
                    if(grid[i][j]->Evo_Stat()==1)
                        cout<<"O ";
                }
                if(grid[i][j]->CreNum()==2)
                {
                    if(grid[i][j]->Evo_Stat()==0)
                        cout<<"x ";
                    if(grid[i][j]->Evo_Stat()==1)
                        cout<<"X ";
                }
            }
            else
                cout<<"  ";
        }
        cout<<endl;
    }
    cout <<"Prey: "<<Prey_Alive<<endl;
    cout <<"Predator: "<<Predator_Alive<<endl;
    cout <<"Queen: "<<E_Prey_Alive<<endl;
    cout <<"Hunger: "<<E_Predator_Alive<<endl;
}
int Grid::count_cre(int crenum)
{
    int count=0;
    for(int i=0; i<MAX;i++)
    {
        for (int j=0;j<MAX;j++)
        {
            if(grid[i][j]!=NULL)
            {
                if(grid[i][j]->CreNum()==crenum&&grid[i][j]->Evo_Stat()==0)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
int Grid::count_Ecre(int crenum)
{
    int count=0;
    for(int i=0; i<MAX;i++)
    {
        for (int j=0;j<MAX;j++)
        {
            if(grid[i][j]!=NULL)
            {
                if(grid[i][j]->CreNum()==crenum&&grid[i][j]->Evo_Stat()==1)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
