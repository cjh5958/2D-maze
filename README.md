2D Game of maze using self-made engine - C++
===

Implement a simple game engine to stand for the game with [SDL2](https://github.com/libsdl-org/SDL.git).  

## TODO list

rendering system  
inputs analyzing  
signal system  
scene  
tilemap  
sounds  
simple scripts  
engine configurating  
    
## Structure Map

```bash
Engine.h
│
├── core
│   │
│   ├── error
│   │   │
│   │   ├── error list
│   │   └── error macro
│   ├── math
│   │   │
│   │   ├── crypto
│   │   ├── math defs
│   │   └── math funcs
│   ├── object
│   │   │
│   │   ├── container
│   │   │   │
│   │   │   ├── hashmap
│   │   │   └── sort array
│   │   ├── script instance
│   │   ├── script template
│   │   └── object.h
│   └── render
├── scene
│   │
│   ├── 2d
│   ├── audio
│   └── gui
│       │
│       ├── button
│       ├── label
│       └── line edit
├── string
├── utility
│   │
│   ├── logger
│   ├── timer
│   └── utility.h
├── application
├── cfg
└── setup.h
```
