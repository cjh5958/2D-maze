#include "engine/Engine.h"

#include "engine/test/test.h"

int main(int argc, char* argv[]) {
    Engine::Vector2 v, a(12, 1.5);
    v = Engine::floor(a);
    Engine::Utility::Logger().Error("% %\n", a, v);
    return Engine::App().run();
}