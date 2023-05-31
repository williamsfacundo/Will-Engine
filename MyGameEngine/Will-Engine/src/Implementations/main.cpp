#include "Core/engine.h"

using namespace WillEngine;

int main()
{
    Engine* engine = new Engine();

    engine->runEngine();

    delete engine;

    return 0;
}

//Del tema "Textures" falta completar bien el ultimo tema: "Texture Units"