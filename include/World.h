#ifndef WORLD_H
#define WORLD_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class World : public sf::Drawable
{
    private:
        int brickSize;
        int X, Y; // game field (in bricks)

        Texture tex;
        mutable Sprite brick;

        Music music;
        Clock clock;

        float timer, delay;

        void draw(RenderTarget &target, RenderStates states) const override;

    public:
        World(int _X, int _Y, int _brickSize = 25);
        World()  = delete;
        ~World() = default;

        void start();
};

#endif // WORLD_H
