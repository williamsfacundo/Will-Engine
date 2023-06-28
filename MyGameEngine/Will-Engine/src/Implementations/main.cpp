#include "game.h"

using namespace WillEngine;

//En la clase que muestran cave y fede se menciona algo importante que no hay que hacer a la hora de implementar modelos
int main() 
{
    Game* engine = new Game();

    engine->runEngine();

    delete engine;

    return 0;
}

//Del tema "Textures" falta completar bien el ultimo tema: "Texture Units"