#pragma once

#include "setup.h"
#include "cfg.h"
#include "utility/utility.h"

namespace Engine
{
    using Utility::Timer;

    class Application
    {
    public:
        /**
         * @brief Start the event loop of the Application.
        */
        int run();

    private:
        bool debug;
        bool executing;
        _CFG_Analyzer config;
        Timer app_timer;
        SDL_Window* primative_window;
        SDL_Renderer* primative_renderer;

        /**
         * @brief Quit every sub-systems of third-party
         */
        void quit(void) noexcept;

    public:
        Application();
        ~Application();

    };

    /**
     * @brief A instance of the Application
    */
    inline Application &App(void) {
        static Application app;
        return app;
    }
}