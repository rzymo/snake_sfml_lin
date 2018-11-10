#include "World.h"
#include "Fruit.h"
#include "Snake.h"
#include "StatusBar.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

using namespace sf;

World::World(int _X, int _Y, int _brickSize)
{
    brickSize = _brickSize;
    X = _X;
    Y = _Y;

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

    Fruit fruit(X, Y);
    Snake snake(X, Y, 3);
    StatusBar sbar(X, Y);

    music.play();   // background music

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

        if (Keyboard::isKeyPressed(Keyboard::Down)  && snake.getDir() != 3) snake.setDir(0);
		if (Keyboard::isKeyPressed(Keyboard::Left)  && snake.getDir() != 2) snake.setDir(1);
		if (Keyboard::isKeyPressed(Keyboard::Right) && snake.getDir() != 1) snake.setDir(2);
		if (Keyboard::isKeyPressed(Keyboard::Up)    && snake.getDir() != 0) snake.setDir(3);
		if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

        if (timer > delay)
        {
            timer = 0.0f;
            snake.move();
        }

        if (snake.getHeadXY() == fruit.getXY())
        {
            fruit.eat();
            snake.grow();
        }

        sbar.setPoints(snake.getLength());
        window.clear();
        window.draw(*this);
        window.draw(fruit);
        window.draw(snake);
        window.draw(sbar);
        window.display();
    }
}
