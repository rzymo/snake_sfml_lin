#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

const int ILE = 5;

class Fruit : public sf::Drawable
{
    private:
        int X, Y, brickSize;
        Vector2i pos;

        Texture tex[ILE+1];
        Sprite sprite[ILE+1];

        SoundBuffer buff;
        Sound sound;

        void newXY();
        void draw(RenderTarget &target, RenderStates states) const override;

    public:
        Fruit(int _X, int _Y, int brickSize = 25);
        Fruit()  = delete;
        ~Fruit() = default;

        void eat()       { sound.play(); newXY(); }
        Vector2i getXY() { return pos; }
};

#endif // FRUIT_H
