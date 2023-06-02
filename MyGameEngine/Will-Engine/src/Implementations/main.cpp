#include "game.h"

using namespace WillEngine;

int main()
{
    Game* engine = new Game();

    engine->runEngine();

    delete engine;

    return 0;
}

//Del tema "Textures" falta completar bien el ultimo tema: "Texture Units"