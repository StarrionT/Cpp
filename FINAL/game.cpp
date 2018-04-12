#include "game.h"
#include "string"

Game::Game()
{
    srand(time(0));//SEED THE RANDOM NUMBER FOR THE WHOLE PROGRAM
    game=new Grid(NUM_PREY,NUM_PREDATOR);
    SetWindow();
    pause=1;
    clicked=0;
    click_x=-30;
    click_y=-30;
    showtitle=1;
}
void Game::SetWindow()
{
    window.create(sf::VideoMode(1000, 600), "Predator vs Prey",sf::Style::Titlebar|sf::Style::Close);//NOT RESIZABLE
    window.setPosition(sf::Vector2i(0,0));//LEFT TOP CORNER
    window.setFramerateLimit(1);
}
void Game::run()
{
    while(window.isOpen())
    {
        process_event();
        update();
        draw();
        window.display();
        window.clear();
    }
}
void Game::update()
{
    if(pause==0)
    {
        game->move();
    }
    if(clicked)
    {
        Clicked_Creature =game->grid[22][0];
        if(Clicked_Creature!=NULL)
        {
//            if(Clicked_Creature->dead==0)
            {
                    click_x=(Clicked_Creature->row-1)*30+1;
                    click_y=(Clicked_Creature->col-1)*30+1;
            }
        }
    }
}

void  Game::process_event()
{
    sf::Event Event;
    while(window.pollEvent(Event))
    {
        if (Event.type==sf::Event::Closed)
            window.close();
        if(Event.type==sf::Event::KeyPressed)
        {
            pause=!pause;
            showtitle=0;

        }
        if(Event.type==sf::Event::MouseButtonPressed)
        {
            if(Event.mouseButton.button==sf::Mouse::Left)
            {
                if(Event.mouseButton.x>0&&Event.mouseButton.x<600&&Event.mouseButton.y<600&&Event.mouseButton.y>0)
                {
                    if(clicked==0)
                    {
                        click_x=Event.mouseButton.x;
                        click_y=Event.mouseButton.y;
                        clicked=1;
                        game->grid[22][0]=game->grid[click_x/30+1][click_y/30+1];
                    }
                    else
                    {
                        if(Clicked_Creature!=NULL)
                        {
                            if(Clicked_Creature->dead==true)
                            {
                                delete Clicked_Creature;
                                Clicked_Creature=NULL;
                                game->grid[22][0]=NULL;

                            }
                        }
                        int i=Event.mouseButton.x/30;
                        int j=Event.mouseButton.y/30;
                        if(i==click_x/30&&j==click_y/30)
                        {
                            clicked=!clicked;
                            cout << "same spot\n";
                        }
                        else
                        {
                            click_x=Event.mouseButton.x;
                            click_y=Event.mouseButton.y;
                            game->grid[22][0]=game->grid[click_x/30+1][click_y/30+1];
                        }
                    }
                }
            }
        }
    }
}

void Game::draw()
{

    sf::Texture back;
    if(!back.loadFromFile("background.jpg",sf::IntRect(0,0,600,600)))
        cout<<"can't open background.jpg\n";
    sf::Sprite X;
    X.setTexture(back);
    window.draw(X);


    sf::Texture tPREY;
    if(!tPREY.loadFromFile("14.png"))
        cout<<"can't open 14.png\n";
    tPREY.setSmooth(1);

    sf::Texture tPREDATOR;
    if(!tPREDATOR.loadFromFile("12.png"))
        cout<<"can't open 12.png\n";
    tPREDATOR.setSmooth(0);
    sf::Texture tQUEEN;
    if(!tQUEEN.loadFromFile("13.png"))
        cout<<"can't open 13.png\n";
    tQUEEN.setSmooth(0);



    sf::RectangleShape square[21][21];
    for(int i=1; i<=20;i++)
    {
        for (int j=1;j<=20;j++)
        {
            square[i][j].setSize(sf::Vector2f(28,28));
            square[i][j].setPosition(sf::Vector2f((i-1)*30,(j-1)*30));

            if(clicked==1&&i==(click_x/30+1)&&j==(click_y/30+1))
            {
                square[i][j].setOutlineThickness(6);
                square[i][j].setOutlineColor(sf::Color::Red);
            }
            else
            {
                square[i][j].setOutlineThickness(1);
                square[i][j].setOutlineColor(sf::Color::White);

            }
            if(game->grid[i][j]!=NULL)
            {

                if(game->grid[i][j]->CreNum()==1)
                {
                    if(game->grid[i][j]->Evo_Stat()==0)
                    {
//                        square[i][j].setFillColor(sf::Color::Green);
                        square[i][j].setTexture(&tPREY);

                    }
                    if(game->grid[i][j]->Evo_Stat()==1)
                    {
//                        square[i][j].setFillColor(sf::Color::Cyan);
                        square[i][j].setTexture(&tQUEEN);
                    }
                }
                if(game->grid[i][j]->CreNum()==2)
                {
                    if(game->grid[i][j]->Evo_Stat()==0)
                    {
//                        square[i][j].setFillColor(sf::Color::Red);
                        square[i][j].setTexture(&tPREDATOR);
                    }
                    if(game->grid[i][j]->Evo_Stat()==1)
                    {
                        square[i][j].setFillColor(sf::Color::Red);
                        square[i][j].setTexture(&tPREDATOR);
                    }
                }
            }
            else
            {
                square[i][j].setFillColor(sf::Color::Transparent);
            }
            window.draw(square[i][j]);
        }
    }
    sf::Font font;
    font.loadFromFile("Comic Sans MS.ttf");


    sf::String infor1;
    sf::Text text(infor1,font,40);
    text.setPosition(sf::Vector2f(620,10));
    text.setColor(sf::Color::Yellow);
    infor1 += "turn: ";
    infor1 += to_string(game->turn);
    text.setString(infor1);
    window.draw(text);

    sf::String infor2;
    sf::Text text2(infor2,font,40);
    text2.setPosition(sf::Vector2f(620,50));
    text2.setColor(sf::Color::Yellow);
    infor2 += "Prey: ";
    infor2 += to_string(game->Prey_Alive);
    text2.setString(infor2);
    window.draw(text2);

    sf::String infor3;
    sf::Text text3(infor3,font,40);
    text3.setPosition(sf::Vector2f(620,90));
    text3.setColor(sf::Color::Yellow);
    infor3 += "Predator: ";
    infor3 += to_string(game->Predator_Alive);
    text3.setString(infor3);
    window.draw(text3);

    sf::String infor4;
    sf::Text text4(infor4,font,40);
    text4.setPosition(sf::Vector2f(620,130));
    text4.setColor(sf::Color::Yellow);
    infor4 += "Queen: ";
    infor4 += to_string(game->E_Prey_Alive);
    text4.setString(infor4);
    window.draw(text4);

    sf::String infor5;
    sf::Text text5(infor5,font,40);
    text5.setPosition(sf::Vector2f(620,170));
    text5.setColor(sf::Color::Yellow);
    infor5 += "Hunger: ";
    infor5 += to_string(game->E_Predator_Alive);
    text5.setString(infor5);
    window.draw(text5);

    if (clicked==1)
    {
        DrawCreInfo();
    }
    if(showtitle==1)
    {
        sf::Texture title;
        if(!title.loadFromFile("11.png"))
            cout<<"can't open 11.png\n";

        sf::Sprite M;
        M.setTexture(title);
        window.draw(M);
    }
}

void Game::DrawCreInfo()
{
    sf::Font font;
    if(!font.loadFromFile("Comic Sans MS.ttf"))
        cout<<"not available.\n";
    sf::String str[10];
    sf::Text text[10];
    try
    {
        Creature*temp=Clicked_Creature;
        if(Clicked_Creature==NULL)
            throw 1;
        if(Clicked_Creature->dead==1)
            throw 'D';
        for(int count=0;count<10;count++)
        {
            text[count].setString(str[count]);
            text[count].setFont(font);
            text[count].setColor(sf::Color::White);
            text[count].setPosition(sf::Vector2f(620,220+count*20));
            text[count].setCharacterSize(20);

            switch (count)
            {

            case 0:
                str[count]+="x: ";
                str[count]+= to_string(temp->row);
                break;
            case 1:
                str[count]+="y: ";
                str[count]+= to_string(temp->col);
                break;
            case 2:
                str[count]+="Turns born: ";
                str[count]+= to_string(game->turn-temp->turn);
                break;
            case 3:
                str[count]+="Starve: ";
                str[count]+= to_string(temp->starve);
                break;
            case 4:
                str[count]+="Food_Eaten: ";
                str[count]+= to_string(temp->Food_Eaten);
                break;
            case 5:
                str[count]+="Offspring: ";
                str[count]+= to_string(temp->Offspring);
                break;
            case 6:
                str[count]+="Evolved: ";
                if(temp->Evolved)
                    str[count]+= "YES";
                else
                    str[count]+=  "NO";
                break;
            case 7:
                str[count]+="Type: ";
                if(temp->CreNum()==1)
                {
                    if(temp->Evo_Stat()==0)
                        str[count]+="Prey";
                    else
                        str[count]+="Queen";
                }
                else if(temp->CreNum()==2)
                {
                    if(temp->Evo_Stat()==0)
                        str[count]+="Predator";
                    else
                        str[count]+="Hunger";
                }
                break;
            case 8:
                str[count]+="Last breed at turn: ";
                str[count]+= to_string(temp->last_breed);
                break;
            case 9:
                str[count]+="Last eat at turn: ";
                str[count]+= to_string(temp->last_eat);
                break;

            }
            text[count].setString(str[count]);
            window.draw(text[count]);
        }
    }
    catch(int)
    {

    }
    catch(char)
    {
        text[0].setString(str[0]);
        text[0].setFont(font);
        text[0].setColor(sf::Color::White);
        text[0].setPosition(sf::Vector2f(620,220));
        text[0].setCharacterSize(40);
        str[0]+="Dead x_x ";
        text[0].setString(str[0]);
        window.draw(text[0]);

    }

}
