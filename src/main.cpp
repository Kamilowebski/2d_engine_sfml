#include "Engine.hpp"

int main()
{
    Engine engine(1280,
        720,
        "Moj silnik 2D",
        false,
        60);

    engine.run();

    return 0;
}
