2D 迷宮遊戲 - C++
===

使用 [SDL2](https://github.com/libsdl-org/SDL.git) 實現Input處理與圖形渲染。

## TODO list

rendering  
inputs analyzing  
signal system  
scene  
tilemap  
sounds  
simple scripts  

    
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
│   ├── ui
│   ├── scene
│   └── typedefs.h
│
├── utility
│   │
│   ├── debug logger
│   ├── timer
│   └── utility.h
├── application
├── cfg
└── setup.h
```