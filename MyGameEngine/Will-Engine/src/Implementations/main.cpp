#include "Core/Engine.h"

using namespace WillEngine;

int main()
{
    Engine* engine = new Engine();

    engine->runEngine();

    delete engine;

    return 0;
}

//https://learnopengl.com/Getting-started/Hello-Triangle