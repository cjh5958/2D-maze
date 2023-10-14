#pragma once

#include "setup.h"
#include "cfg.h"
#include "utility/utility.h"
#include "core/error/error_list.h"

namespace Engine
{
    using Utility::_Timer;

    class Application
    {
    public:

        void create_window();

        /**
         * @brief Start the main loop of the application.
        */
        Error run();

    private:

        bool debug;
        bool executing;
        _CFG_Analyzer config;
        _Timer app_timer;
        SDL_Window* primative_window;

        /**
         * @brief Quit every sub-systems of third-party
         */
        void quit(void) noexcept;

    public:
        Application();
        ~Application(){}

    };  //class Application

    /**
     * @brief Instance of the application
     * 
     * @return Application
    */
    inline Application &App(void) {
        static Application app;
        return app;
    }

}   //namespace Engine