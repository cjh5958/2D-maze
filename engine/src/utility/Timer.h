#pragma once

#include "../setup.h"

namespace Engine
{
    namespace Utility
    {
        class Timer
        {
        public:
            void start();
            void restart();
            void pause();
            Uint64 time();  //fetch time

            bool isPaused() {return this->paused;}
            bool isStarted() {return this->started;}

        private:
            bool started, paused;
            Uint64 startTick, pauseTick;

        public:
            Timer();
        };
    }
}