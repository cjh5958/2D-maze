#include "engine/Engine.h"

#include "engine/test/test.h"

int main(int argc, char* argv[]) {
    using Engine::Vector2;

    Engine::Vector2 a(3, 4), b(4, 5);
    a = a + b;
    std::cout << a << '\n';

    return Engine::App().run();
}