# So Long

[![CI](https://github.com/man-Yocto/so_long/actions/workflows/ci.yml/badge.svg)](https://github.com/man-Yocto/so_long/actions/workflows/ci.yml)

A 2D tile-based game implemented in C using the miniLibX graphics library. Navigate through maps, collect items, and reach the exit while avoiding enemies.

## Features

- **Player Movement**: WASD or Arrow keys to move in all directions
- **Map Parsing**: Load and validate custom .ber map files
- **Collectibles**: Gather all collectible items before reaching the exit
- **Enemy AI**: Dynamic enemy movement on the map
- **Win/Lose Conditions**: Complete objectives to win or lose the game
- **Graphics Rendering**: 64x64 tile-based graphics with sprite system

## Requirements

- GCC compiler
- X11 development libraries
- Make
- Linux system (miniLibX is X11-based)

## Installation

### Prerequisites (Ubuntu/Debian)

```bash
sudo apt-get install xorg libxext-dev zlib1g-dev
```

### Build

```bash
make
```

This will compile the custom libft library and the main executable.

## Usage

```bash
./so_long maps/map.ber
```

### Map Format

Map files use the `.ber` extension and consist of:
- `1`: Walls
- `0`: Floor (empty space)
- `P`: Player starting position (exactly one required)
- `E`: Exit (exactly one required)
- `C`: Collectible items (at least one required)
- `X`: Enemy (optional)

### Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Quit game |

## Project Structure

```
.
├── src/                    # Source files
│   ├── main.c             # Entry point
│   ├── map_read.c         # Map file parsing
│   ├── map_check.c        # Map validation
│   ├── display.c          # Window initialization
│   ├── draw.c             # Map rendering
│   ├── hooks_group.c      # Event handling
│   ├── get_next_line.c    # File reading utility
│   └── ...
├── includes/
│   ├── so_long.h          # Main header
│   ├── libft/             # Custom C library
│   └── minilibx-linux/    # Graphics library
├── maps/                  # Example map files
└── images/                # Game sprites (.xpm format)
```

## Map Validation

The game validates maps for:
- Rectangular shape
- Surrounded by walls
- Exactly one player start position
- Exactly one exit
- At least one collectible
- Valid path from player to exit and all collectibles

## Game Mechanics

- **Movement Counter**: Displays number of moves to reach the exit
- **Collectible Tracking**: Must collect all items before exit is functional
- **Enemy Detection**: Game ends if player collides with an enemy
- **Exit Condition**: Player must collect all items and reach the exit to win

## Compilation Details

- Custom `libft` library provides standard C library functions
- `miniLibX` handles all graphics rendering and event management
- Supports dynamic map sizes (within configuration limits)
- Modular architecture for easy debugging and maintenance

## Makefile Commands

```bash
make        # Build the executable
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Full rebuild
```

## Key technical challenges

- **Map validation** — checking the map is rectangular, closed by walls, and has exactly one player
  and exit and at least one collectible.
- **Reachability** — a flood fill from the player's position proves every collectible and the exit
  can actually be reached.
- **Event-driven rendering** — redrawing tiles from MiniLibX key and loop hooks without flicker.
- **Clean shutdown** — freeing images, the map and the MLX window on every exit path, including the
  window close button.

## What I learned

<!-- TODO: write this section yourself -->

## Author

yocto (yocto@student.42.fr)

## License

This project is part of the 42 School curriculum.
