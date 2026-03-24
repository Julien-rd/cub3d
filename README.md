*This project has been created as part of the 42 curriculum by vmanuyko and jromann.*

## Description

Cub3D is a 3D rendering project inspired by Wolfenstein 3D. It uses raycasting to simulate a 3D perspective from a 2D map, allowing the player to navigate and view the environment as if it were three-dimensional.

Cub3D is designed to run in a Linux environment and requires the MiniLibX graphics library to be installed and properly linked, along with the standard math library.

All necessary setup steps are explained in the [Instructions](#instructions) section and implemented within the project’s Makefile.

## Parsing

The parsing phase is responsible for reading and validating the `.cub` configuration file before the rendering engine starts.

A valid map in Cub3D must follow strict rules to ensure the game behaves correctly:

* The file must contain texture paths and color definitions before the map layout.
* The map itself is composed of characters representing different elements:

  * `1` → wall
  * `0` → empty space
  * `N`, `S`, `E`, `W` → player starting position and orientation

### Map Requirements

* The map must be **completely enclosed by walls**.
  This means the player can never reach an open space or “outside” the map.
* There must be **exactly one player starting position**.
* The map cannot contain invalid characters.
* Spaces inside the map must be surrounded by walls.

---
## Rendering

### *Line Drawing — Bresenham’s Algorithm*

For drawing lines on the minimap (such as the player’s direction), the project uses Bresenham’s Line Algorithm.

Bresenham’s algorithm is an efficient, integer-based method for rasterizing lines. It determines which pixels best approximate a straight line between two points without using floating-point arithmetic. This makes it ideal for real-time rendering in grid-based systems, ensuring:

- Precision across all directions (360°)
- Consistent pixel alignment
- High performance due to integer-only operations

### *Wall Detection — DDA Algorithm*

To render the 3D scene, Cub3D uses the Digital Differential Analyzer (DDA) algorithm for raycasting.

For each vertical stripe of the screen:
A ray is cast from the player’s position in a specific direction.
The DDA algorithm steps through the map grid cell by cell.
The ray stops when it hits a wall.
The distance to that wall is used to calculate the height of the vertical slice.

This process is repeated for every column of the screen, creating the illusion of depth and perspective.

## Instructions

***MLX library installation***
```
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
```
By default, this project expects libmlx.a to be located in:
```
/usr/lib
```
If the library is located elsewhere, the Makefile must be adjusted accordingly.

***Compilation***
```
make
```

***Run the program*** 
```
./cub3D <map.cub>
```
#### *Note:* in `maps/` there are examples of valid/invalid maps.

## Recourses

In this project AI was used for: 

- algorithm explanations with examples
- deep understanding of some concepts like FOV
- finding new test cases and debugging
- adjusting design with getting the colours wanted

These are useful links we used while building the project:

[Raycasting tutorial](https://lodev.org/cgtutor/raycasting.html)

[Another raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-8/#google_vignette)

[Raycasting visualiser](https://editor.p5js.org/KernelOverseer/full/Ilst053ZC)

[Cub3d project guide](https://hackmd.io/@nszl/H1LXByIE2#player-direction-vector-and-camera-vector)

[Github repository with Cub3d guide](https://github.com/Toufa7/Cub3D/tree/main)

[Bresenham's algorithm explained](https://www.csfieldguide.org.nz/en/chapters/computer-graphics/drawing-lines-and-circles/#bresenham-s-line-algorithm)

[ChatGPT discussion about FOV angle](https://chatgpt.com/share/69b825cd-c164-8004-9cdd-873c08cebaa9)