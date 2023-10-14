#include "Timer.h"
using namespace Engine::Utility;


_Timer::_Timer() :
    startTick(0),
    pauseTick(0),
    paused(false),
    started(false){}


void _Timer::start() {
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

void _Timer::pause() {
    if(started) {
        this->paused = true;
        this->started = false;
        this->pauseTick = SDL_GetTicks64() - startTick;
    }
}

void _Timer::restart() {
    this->started = false;
    this->paused = false;
    this->start();
}

Uint64 _Timer::time() {
    if(paused) return pauseTick;
    else if(started) return SDL_GetTicks64() - startTick;
    return 0;
}