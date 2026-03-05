# Arkanoid Game

A classic clone of the arcade game Arkanoid, written in C++ using the SFML 3.0 library. Control the paddle, bounce the ball, and destroy colorful blocks to complete all levels!

## Features
- Multiple levels with unique block configurations
- Score tracking and high score saving
- Different block types with distinct colors
- Smooth ball and paddle animations
- Game messages: GAME OVER, NEW LEVEL, VICTORY
- Level configuration via text file
- Sound effects for game events
- Attractive graphics and backgrounds

## Controls
- **Left**: ← (left arrow) or `A`
- **Right**: → (right arrow) or `D`
- **Start/Restart**: Space
- **Quit game**: Escape

## Project Structure
```plaintext
src/
├── main.cpp 
├── ball.cpp              # Ball logic
├── block.cpp             # Block logic
├── block_intersection.cpp # Block collision handling
├── game.cpp              # Main game logic
├── levels_manager.cpp    # Level management
├── main.cpp              # Entry point
├── message_box.cpp       # Message system
├── paddle_intersection.cpp # Paddle collision handling
├── puddle.cpp            # Paddle logic
├── resources_manager.cpp # Resource management
├── score_board.cpp       # Score system
└── wall_intersection.cpp # Wall collision handling

include/
├── ball.h
├── block.h
├── block_intersection.h
├── game.h
├── levels_manager.h
├── message_box.h
├── paddle_intersection.h
├── puddle.h
├── resources_manager.h
├── score_board.h
└── wall_intersection.h

resources/
├── fonts/                # Fonts for text
│   ├── karmatic_arcade.tif
├── sounds/               # Sound effects
│   ├── game-lost.wav     # Game over sound
│   ├── game-won.wav      # Win game sound
│   ├── next_level.wav    # Level complete sound
│   └── victory.wav       # Victory sound
├── textures/             # Graphic assets
│   ├── background.png    # Background image
│   ├── objects.png       # Game object sprites
│   └── splashscreen.png  # Splash screen
└── levels.txt            # Level configuration
```

## Level Configuration
Levels are configured via the `resources/levels.txt` file (format: 10 columns × 16 rows):

| Symbol | Color       |
|--------|------------|
| `.`    | Empty      |
| `R`    | Red        |
| `O`    | Orange     |
| `Y`    | Yellow     |
| `G`    | Green      |
| `C`    | Cyan       |
| `B`    | Blue       |
| `p`    | Purple     |

Example configuration:
```txt
# LVL 1:
..........
RRRRRRRRRR
OOOOOOOOOO
YYYYYYYYYY
GGGGGGGGGG
CCCCCCCCCC
BBBBBBBBBB
pppppppppp
..........
..........
..........
..........
..........
..........
..........
..........
```

### Running the Game (Recommended)
The easiest way to play the game is to download a prebuilt Windows version.
1. Go to the **Releases** section of this GitHub repository.
2. Download the latest release archive, for example: `Arcanoid-win64.zip`.
3. Extract the contents of the archive to any folder.
4. Run `Arcanoid.exe`.
All required SFML DLLs and game resources are already included in the archive, so no additional installation is needed.
#### System Requirements
- Windows 10/11 64-bit
- A GPU/driver capable of running SFML-based OpenGL applications
---
### Author
DmitriuAndreevich
### License
MIT License
