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
    ;
}
