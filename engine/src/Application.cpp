#include "Application.h"
using namespace Engine;

Application::Application():
    config("format.cfg"),
    executing(false),
    primative_window(nullptr){
        this->debug = to_bool(config.get("Debug.Enable"));
        SDL_Init(SDL_INIT_EVERYTHING);
}

void Application::quit() noexcept
{
    SDL_DestroyWindow(this->primative_window);
    SDL_Quit();
}

Error Application::run() {
    this->executing = 1;
    this->app_timer.start();

    Utility::Logger().System("Debugging mode has been enabled.\n");

    int display_x, display_y;
    if(to_int(config.get("window.x"))==-1) display_x = SDL_WINDOWPOS_CENTERED;
    else display_x = to_int(config.get("window.x"));
    if(to_int(config.get("window.y"))==-1) display_y = SDL_WINDOWPOS_CENTERED;
    else display_y = to_int(config.get("window.y"));

    if(to_bool(config.get("window.AlwaysOnTop")))      flg |= SDL_WINDOW_ALWAYS_ON_TOP;
    if(to_bool(config.get("window.Highdpi")))          flg |= SDL_WINDOW_ALLOW_HIGHDPI;
    if(to_bool(config.get("window.Fullscreen")))       flg |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    if(to_bool(config.get("window.Hidden")))           flg |= SDL_WINDOW_HIDDEN;

    this->primative_window = SDL_CreateWindow(
        config.get("window.Name").c_str(),
        display_x,
        display_y,
        to_int(config.get("window.w")),
        to_int(config.get("window.h")),
        this->flg
    );

    SDL_Event e;
    while(executing) {
        if(SDL_WaitEvent(&e) != 0){
            if(e.type == SDL_QUIT) this->executing = false;
        }
        //break;
    }

    this->app_timer.pause();
    this->quit();

    Utility::Logger().System("Executed application using % seconds\n", this->app_timer.time() / 1000.f);

    return Error::OK;
}