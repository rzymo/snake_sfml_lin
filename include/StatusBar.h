#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <SFML/Graphics.hpp>

using namespace sf;

class StatusBar : public sf::Drawable
{
    private:
        int X, Y, brickSize;

        Font font;
        Text textPts;
        Texture tex;
        mutable Sprite sprite;

        void draw(RenderTarget &target, RenderStates states) const override;

    public:
        StatusBar(int _X, int _Y, int _brickSize = 25);
        StatusBar()  = delete;
        ~StatusBar() = default;

        void setPoints(int _pts);
};

#endif // STATUSBAR_H
