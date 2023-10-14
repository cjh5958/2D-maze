#include "Application.h"
using namespace Engine;

Application::Application():
    config("format.cfg"),
    executing(false),
    primative_window(nullptr){
        this->debug = to_bool(config.get("debug_mode"));
        SDL_Init(SDL_INIT_EVERYTHING);
}

void Application::quit() noexcept
{
    SDL_DestroyWindow(this->primative_window);
    SDL_Quit();
}

Error Application::run() {
    this->executing = true;
    this->app_timer.start();

    int display_x, display_y;
    if(config.get("window_x")=="center") display_x = SDL_WINDOWPOS_CENTERED;
    else display_x = atoi(config.get("window_x").c_str());
    if(config.get("window_y")=="center") display_y = SDL_WINDOWPOS_CENTERED;
    else display_y = atoi(config.get("window_y").c_str());

    Uint32 flg = 0U;
    if(to_bool(config.get("always_on_top")))    flg |= SDL_WINDOW_ALWAYS_ON_TOP;
    if(to_bool(config.get("highdpi")))          flg |= SDL_WINDOW_ALLOW_HIGHDPI;
    if(to_bool(config.get("fullscreen")))       flg |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    if(to_bool(config.get("hidden")))           flg |= SDL_WINDOW_HIDDEN;

    this->primative_window = SDL_CreateWindow(
        config.get("window_name").c_str(),
        display_x,
        display_y,
        atoi(config.get("window_w").c_str()),
        atoi(config.get("window_h").c_str()),
        flg
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