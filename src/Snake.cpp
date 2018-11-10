#include "Snake.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Snake::Snake(int _X, int _Y, int _segm, int _brickSize)
{
    X = _X;
    Y = _Y;
    brickSize = _brickSize;
    dir = 0;

    s.resize(_segm);

    if (!tex[0].loadFromFile("res/head.png")) exit(1);
    head.setTexture(tex[0]);
    if (!tex[1].loadFromFile("res/segm.png")) exit(1);
    segm.setTexture(tex[1]);
    if (!buff.loadFromFile("res/bang.wav")) exit(1);
    sound.setBuffer(buff);
}

void Snake::draw(RenderTarget & target, RenderStates states) const
{
	head.setPosition(static_cast<float>(s[0].x*brickSize), static_cast<float>(s[0].y*brickSize));
	target.draw(head, states);

	for (size_t i = 1; i < s.size(); i++)
	{
		segm.setPosition(static_cast<float>(s[i].x*brickSize), static_cast<float>(s[i].y*brickSize));
		target.draw(segm, states);
	}
}

void Snake::move()
{
    for (size_t i = s.size()-1; i > 0; --i)
    {
        s[i].x = s[i-1].x;
        s[i].y = s[i-1].y;
    }

    if (dir == 0) s[0].y += 1; // down
    if (dir == 1) s[0].x -= 1; // left
    if (dir == 2) s[0].x += 1; // right
    if (dir == 3) s[0].y -= 1; // up

    if (s[0].x > X-1) s[0].x = 0;
    if (s[0].x < 0) s[0].x = X-1;
    if (s[0].y > Y-1) s[0].y = 0;
    if (s[0].y < 0) s[0].y = Y-1;

    for (size_t i = 1; i < s.size(); i++)
        if ((s[0].x == s[i].x) && (s[0].y == s[i].y))
        {
            s.resize(i);
            sound.play();
        }
}
