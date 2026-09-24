*This project has been created as part of the 42 curriculum by nalfonso, matmagal.*

# cub3D

## Description

**cub3D** is our first raycasting engine, inspired by Wolfenstein 3D — the first true first-person shooter. The goal is to render a real-time, first-person 3D view of a 2D maze described in a text file, using the ray-casting principle: for every column of the screen, a ray is cast from the player's position until it hits a wall, and the distance to that hit determines how tall the wall slice is drawn.

The project is built entirely in C, on top of MiniLibX for window creation and pixel drawing — no external 3D engine or library is used. It covers:

- Parsing and validating a custom `.cub` scene description file (textures, floor/ceiling colors, and the map grid)
- A DDA (Digital Differential Analysis) raycasting algorithm to detect walls per screen column
- Wall textures that differ depending on which cardinal direction (North/South/East/West) the wall faces
- Solid floor and ceiling colors
- Real-time player movement and camera rotation, with wall collision
- Clean exit on `ESC` or on closing the window

## Instructions

### Requirements

- Linux (developed/tested on WSL Ubuntu 22.04)
- `X11` and `Xext` development libraries, `make`, a C compiler (`cc`)
- MiniLibX (bundled in `minilibx-linux/`, built automatically by the Makefile)

### Compilation

```sh
make        # builds MiniLibX (if needed) and the Cub3d binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

### Execution

```sh
./Cub3d <path/to/map.cub>
```

Example:

```sh
./Cub3d maps/test.cub
```

### Controls

| Key             | Action                |
|-----------------|------------------------|
| `W`             | Move forward            |
| `S`             | Move backward            |
| `A`             | Strafe left               |
| `D`             | Strafe right               |
| `←` Left arrow  | Turn camera left          |
| `→` Right arrow | Turn camera right         |
| `ESC`           | Close the window cleanly   |
| Window's close button (✕) | Close the window cleanly |

### `.cub` scene file format

A scene file has two parts: resource directives (in any order, separated by one or more empty lines), followed by the map grid, which must always come last.

**Textures** — one path per cardinal direction:

```
NO ./textures/wall_metal.xpm
SO ./textures/wall_hazard.xpm
WE ./textures/floor_concrete.xpm
EA ./textures/ceiling_light.xpm
```

**Colors** — floor (`F`) and ceiling (`C`), as `R,G,B` in `[0,255]`:

```
F 100,150,50
C 30,80,200
```

**Map grid** — made of exactly 6 valid characters:

- `1` — wall
- `0` — empty walkable space
- `N` / `S` / `E` / `W` — the player's single start position and starting facing direction
- ` ` (space) — void, valid as long as the walkable area stays fully enclosed by walls

Example:

```
111111111111111111111111
100000000000000000000001
100011111111111111110001
100010000000000000010001
100010111111111111010001
100010100000000001010001
100010100111111101010001
100010100100000001010001
100000000100N00100000001
100010100100000101010001
100010100111111101010001
100010100000000001010001
100010111111111111010001
100010000000000000010001
100011111111111111110001
100000000000000000000001
111111111111111111111111
```

If any part of the file is malformed, the program exits cleanly and prints `Error\n` followed by an explicit message describing the problem.

## Resources

Classic references used to understand and implement raycasting and the MiniLibX API:

- [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html) — the primary reference for the DDA algorithm, `sideDist`/`deltaDist` accumulation, and `perpWallDist`/wall-slice-height derivation
- [42's MiniLibX documentation and header](https://github.com/42Paris/minilibx-linux) — window/image API (`mlx_new_window`, `mlx_new_image`, `mlx_get_data_addr`, `mlx_put_image_to_window`, `mlx_hook`, `mlx_loop_hook`)
- [Wikipedia — Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D) and the [original game](http://users.atw.hu/wolf3d/) for historical/design context
- 42's `cub3D` subject (this repository's `en.subject.pdf`)

**Use of AI:** AI was used as a tutor and code reviewer, never as a code generator for this project — every line of raycasting, movement, parsing, and rendering logic was written by nalfonso and matmagal themselves.

- **Concept teaching:** the camera/ray direction model (cameraX, ray direction as `dir + plane*cameraX`), the DDA loop (`deltaDist`, `sideDist`, step direction), `perpWallDist` and wall-slice height/draw bounds, and side-based texture selection were explained conceptually, part by part, with the implementation left entirely to us.
- **Debugging support:** for real bugs encountered during development (an uninitialized loop counter, a missing map bounds check causing an infinite DDA loop, an inverted `perpWallDist` subtraction, a texture pointer left uninitialized after `mlx_get_data_addr`, and a keyboard-input architecture issue causing input lag), AI was used to point out *where* and *why* something was wrong through questions and hints — not to write the fix. All fixes in the codebase were written and understood by us.
