#include "World.h"
#include <SFML/Graphics.hpp>

int main()
{
    const int brickSize = 25;
    int x = 30, y = 20;         // board's size
                                // TODO: menu to adjust above values
    World myWorld(x, y, brickSize);
    myWorld.start();

    return 0;
}
