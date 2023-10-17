2D 迷宮遊戲 - C++
===

使用 [SDL2](https://github.com/libsdl-org/SDL.git) 實現Input處理與圖形渲染。

## TODO list

Renderer  
I/O  
Signal system  
Scene
Tilemap  
聲音控制  
動畫  
腳本鏈結  
    
    
## Structure Map

```bash
Engine.h
│
├── core
│   │
│   ├── error
│   │   │
│   │   └── error list
│   ├── math
│   │   │
│   │   ├── math funcs
│   │   ├── math defs
│   │   └── aabb
│   ├── object
│   ├── scene
│   └── typedefs
│
├── utility
│   │
│   ├── debug logger
│   ├── timer
│   └── utility.h
│
├── application
├── cfg
└── setup.h
```