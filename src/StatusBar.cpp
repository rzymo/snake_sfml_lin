#include "StatusBar.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

StatusBar::StatusBar(int _X, int _Y, int _brickSize)
{
    X = _X;
    Y = _Y;
    brickSize = _brickSize;

    if (!tex.loadFromFile("res/status.png")) exit(1);
    sprite.setTexture(tex);

    if (!font.loadFromFile("res/arial.ttf")) exit(1);

    textPts.setFont(font);
    textPts.setCharacterSize(13);
    textPts.setFillColor(Color::Black);
    textPts.setPosition(5.0f, static_cast<float>(brickSize * Y + 3));
}

void StatusBar::setPoints(int pts)
{
//	obie formy poprawne, druga tylko do zmiennych lokalnych, pierwsza moze siegnac np. do pol klasy
//	txt_pts.setString("POINTS: " + [](int p) { return p<10 ? "0" + to_string(p) : to_string(p); }(pts));
	textPts.setString("POINTS: " + [pts]() { return pts<10 ? "0" + to_string(pts) : to_string(pts); }());
}

void StatusBar::draw(RenderTarget &target, RenderStates states) const
{
	for (int i = 0; i < X; i++)
	{
		sprite.setPosition(static_cast<float>(i*brickSize), static_cast<float>(Y*brickSize));
		target.draw(sprite);
	}
	target.draw(textPts);
}
