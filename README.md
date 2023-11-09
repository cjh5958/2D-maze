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
¢x
¢u¢w¢w core
¢x   ¢x
¢x   ¢u¢w¢w error
¢x   ¢x   ¢x
¢x   ¢x   ¢u¢w¢w error list
¢x   ¢x   ¢|¢w¢w error catch
¢x   ¢u¢w¢w math
¢x   ¢x   ¢x
¢x   ¢x   ¢u¢w¢w crypto
¢x   ¢x   ¢u¢w¢w math defs
¢x   ¢x   ¢|¢w¢w math funcs
¢x   ¢u¢w¢w object
¢x   ¢x   ¢x
¢x   ¢x   ¢u¢w¢w container
¢x   ¢x   ¢x   ¢x
¢x   ¢x   ¢x   ¢u¢w¢w hashmap
¢x   ¢x   ¢x   ¢|¢w¢w sort array
¢x   ¢x   ¢u¢w¢w script instance
¢x   ¢x   ¢u¢w¢w script template
¢x   ¢x   ¢|¢w¢w object.h
¢x   ¢|¢w¢w render
¢u¢w¢w scene
¢x   ¢x
¢x   ¢u¢w¢w 2d
¢x   ¢u¢w¢w audio
¢x   ¢|¢w¢w gui
¢x       ¢x
¢x       ¢u¢w¢w button
¢x       ¢u¢w¢w label
¢x       ¢|¢w¢w line edit
¢u¢w¢w string
¢u¢w¢w utility
¢x   ¢x
¢x   ¢u¢w¢w debug logger
¢x   ¢u¢w¢w timer
¢x   ¢|¢w¢w utility.h
¢u¢w¢w application
¢u¢w¢w cfg
¢|¢w¢w setup.h
```