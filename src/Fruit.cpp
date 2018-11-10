#include "Fruit.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Fruit::Fruit(int _X, int _Y, int _brickSize)
{
    X = _X;
    Y = _Y;
    brickSize = _brickSize;

    for (int i = 1; i <= ILE; i++)
    {
        if (!tex[i].loadFromFile("res/fruit" + to_string(i) + ".png")) exit(1);
        sprite[i].setTexture(tex[i]);
    }

    newXY();

    if (!buff.loadFromFile("res/eat.wav")) exit(1);
    sound.setBuffer(buff);
    sound.setVolume(80);
}

void Fruit::newXY()
{
    srand(static_cast<int>(time(0)));
    pos.x = rand() % X;
    pos.y = rand() % Y;

	sprite[0].setTexture(*sprite[rand() % ILE + 1].getTexture());
	sprite[0].setPosition(static_cast<float>(pos.x * brickSize), static_cast<float>(pos.y * brickSize));
}

void Fruit::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(*sprite, states);	// target.draw(sprite[0], states);
}
