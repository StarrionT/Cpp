#ifndef GAME_H
#define GAME_H
const int NUM_PREDATOR=5;
const int NUM_PREY=365;
#include<ctime>
#include<cstdlib>
#include <grid.h>
#include <SFML/Graphics.hpp>
#include <creature.h>
//THIS CLASS IS THE CLASS WHICH BOTH GRID AND GRAPHIC DISPLAY ARE IMPLMENTED.
class Game
{
public:
    Game();
    ~Game(){/*game->~Grid(); */delete game;}
    void SetWindow();//SET UP THE WINDOW OF THE GRAPHIC DISPLAY
    void run();//THE ONLY THING NEEDED FOR MAIN CPP
    void process_event();//PROCESSING THE EVENTS OF THE USER IN THE WINDOW
    void draw();//DRAW THE GRID AND GRID STAT ON THE WINDOW
    void DrawCreInfo();//DRAW THE CLICKED CREATURE INFO
    void update();//UPDATING THE GRID AND DISPLAY

private:
    Grid* game;
    sf::RenderWindow window;



    bool pause; //BOOLEAN FOR PAUSING
    bool clicked;//BOOLEAN FOR WHETHER USER IS CLICKING ON ONE CREATURE
    int click_x,click_y;//COORD OF CLICKED CREATURE
    bool showtitle;//BOOLEAN FOR SHOWING TITLE
    Creature* Clicked_Creature;//POINTER WHICH POINTS TO THE CLICKED CREATURE
};




#endif // GAME_H
