#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Snake : public sf::Drawable
{
    private:
        int X, Y, brickSize;
        int dir;

        vector<Vector2i> s;
        Texture tex[2];
        mutable Sprite head, segm;

        SoundBuffer buff;
        Sound sound;

        void draw(RenderTarget &target, RenderStates states) const override;

    public:
        Snake(int _X, int _Y, int _segm, int _brickSize = 25);
        Snake()  = delete;
        ~Snake() = default;

        int getLength()      { return s.size(); }
        int getDir()         { return dir; }
        Vector2i getHeadXY() { return s[0]; }
        void setDir(int _d)  { dir = _d; }
        void grow()          { s.resize(s.size() + 1); }
        void move();
};

#endif // SNAKE_H
