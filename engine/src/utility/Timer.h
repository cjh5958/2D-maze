#pragma once

#include "../setup.h"

namespace Engine
{
    namespace Utility
    {
        class _Timer
        {
        public:
            void start();
            void restart();
            void pause();
            Uint64 time();  //fetch time

            bool Paused() {return this->paused;}
            bool Started() {return this->started;}

        protected:
            bool started, paused;
            Uint64 startTick, pauseTick;

        public:
            _Timer();
        };
    }
}