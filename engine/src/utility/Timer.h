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
            Uint32 time();  //fetch time

            bool isPaused() {return this->paused;}
            bool isStarted() {return this->started;}

        private:
            bool started, paused;
            Uint32 startTick, pauseTick;

        public:
            Timer();
        };
    }
}