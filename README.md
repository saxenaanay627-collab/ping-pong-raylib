#  Raylib Mini Arcade — C Game Collection
A modular **multi-game launcher** built using **C** and **raylib**.
This project combines several small games (Snake, Tic Tac Toe, Ping Pong) into a single executable using a start menu system.
---
##  Features

*  Modular architecture (each game is a separate `.c` file)
*  Texture-based rendering using raylib
*  Keyboard & mouse input
*  Single launcher executable
*  Restartable gameplay loops
*  Grid-based Snake implementation
---
##  Project Structure
```
game_in_c/
│
├── startmenu.c        # Main launcher (contains main())
├── snake_game.c       # Snake game logic (void snake_game())
├── tictactoe.c        # Tic Tac Toe logic (void tictactoe())
├── ping_pong.c        # Ping Pong logic (void ping_pong())
│
├── snake_game.h
├── tictactoe.h
├── ping_pong.h
│
└── assets/
    ├── background.png
    ├── snake.png
    └── food.png
```
---
##  Requirements
* C compiler (MinGW / GCC recommended)
* raylib installed
https://www.raylib.com/
---
##  Build Instructions (Windows + MinGW)
Compile all modules together:
```
gcc startmenu.c tictactoe.c snake_game.c ping_pong.c -o main.exe ^
-IC:\raylib\raylib\src ^
-LC:\raylib\raylib\src ^
-lraylib -lopengl32 -lgdi32 -lwinmm
```
Run:
```
main.exe
```
---
##  Controls

### Snake
* Arrow Keys — Move
* R — Restart after Game Over
  
### Tic Tac Toe
* Mouse Click — Place mark

### Ping Pong

* Arrow Keys / Assigned controls

---

##  Architecture Notes

* Only **startmenu.c** contains `main()`.
* Each game exposes a function:

  * `void snake_game(void);`
  * `void tictactoe(void);`
  * `void ping_pong(void);`
* Textures are loaded once and drawn using `DrawTexturePro()` for scaling.

---

##  Common Issues

###  `multiple definition of main`

Make sure only `startmenu.c` has `main()`.

###  `undefined reference to WinMain`

You tried compiling a game file alone.
Compile ALL `.c` files together.

###  `implicit declaration of function`

Include the correct `.h` file in `startmenu.c`.

---

##  Future Improvements

* Animated snake head rotation
* Sound effects (eat / game over)
* Particle effects
* Pause menu
* Better UI transitions

---

##  License

Educational project built using raylib.

---

Made with ❤️ using C + raylib
