#include "World.h"
//#include "fruit.h"
//#include "snake.h"
//#include "status_bar.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

using namespace sf;

World::World(int _X, int _Y, int _brickSize)
{
    brickSize = _brickSize;
    X = _X;
    Y = _Y;
    W = brickSize * X;
    H = brickSize * (Y+1); // +1 for status_bar

    timer = 0.0f;
    delay = 0.1f;

    if (!music.openFromFile("res/true.ogg")) exit(1);
    music.setLoop(true);
    music.setVolume(30);

    if (!tex.loadFromFile("res/brick.png")) exit(1);
    brick.setTexture(tex);
}

void World::draw(RenderTarget &target, RenderStates states) const
{
    for (int i = 0; i < X; i++)
        for (int j = 0; j < Y; j++)
        {
            brick.setPosition(static_cast<float>(i*brickSize), static_cast<float>(j*brickSize));
            target.draw(brick, states);
        }
}

void World::start()
{
    RenderWindow window(VideoMode(X*brickSize, (Y+1)*brickSize), "Snejk!");
    window.setFramerateLimit(60);

    //Fruit fruit(X, Y);
    //Snake snake(X, Y, 3);
    //Status_bas sbar(X, Y);

    music.play();

    while (window.isOpen())
    {
        timer += clock.getElapsedTime().asSeconds();
        clock.restart();

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*this);
        window.display();
    }

}
