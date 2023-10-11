#include "Timer.h"
using namespace Engine::Utility;


Timer::Timer() {
    this->startTick = 0;
    this->pauseTick = 0;
    this->paused = false;
    this->started = false;
}


void Timer::start() {
    if(!started && !paused) {
        /*First time*/
        this->started = true;
        this->startTick = SDL_GetTicks64();
    }
    else if(paused) {
        this->started = true;
        this->paused = false;
        this->startTick = SDL_GetTicks64() - pauseTick;
    }
}

void Timer::pause() {
    if(started) {
        this->paused = true;
        this->started = false;
        this->pauseTick = SDL_GetTicks64() - startTick;
    }
}

void Timer::restart() {
    this->started = false;
    this->paused = false;
    this->start();
}

Uint64 Timer::time() {
    if(paused) return pauseTick;
    else if(started) return SDL_GetTicks64() - startTick;
    return 0;
}