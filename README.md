# MiniRT

MiniRT is a 3D rendering project written in C with MiniLibX. The current
engine generates an image using ray tracing and displays the scene in a
`1080x720` window.

## Current features

- One ray generated for each pixel.
- Camera coordinate system built from its direction vector.
- Ray-sphere intersection.
- Rendering of multiple spheres with individual object colors.
- Ambient lighting.
- Diffuse lighting with multiple light sources.
- Real-time camera movement and orientation.
- Resource cleanup when the window is closed.

The current scene is created directly in `srcs/main.c`:

- a camera positioned at `(0, 0, -10)`;
- three spheres with different colors and sizes;
- two white lights;
- ambient lighting.

## Requirements

- A C compiler compatible with the options used by the Makefile.
- `make`.
- MiniLibX Linux in the `minilibx-linux/` directory.
- The X11 (`X11` and `Xext`) and `libm` libraries.

## Build and run

```bash
make
./minirt
```

To remove object files and compiled dependencies:

```bash
make clean
```

To also remove the executable:

```bash
make fclean
```

To rebuild the project from scratch:

```bash
make re
```

## Controls

| Key | Action |
| --- | ------ |
| `W` | Move the camera up |
| `S` | Move the camera down |
| `A` | Move the camera left |
| `D` | Move the camera right |
| `Q` | Move the camera forward |
| `E` | Move the camera backward |
| `T` | Look up |
| `G` | Look down |
| `F` | Look left |
| `H` | Look right |
| `R` | Reset the camera |
| `Escape` | Close the program |

## Project structure

- `srcs/`: rendering, intersections, lighting, camera control, and resource
  cleanup;
- `inc/minirt.h`: project structures and prototypes;
- `libft/`: utility functions used by the program;
- `minilibx-linux/`: MiniLibX dependency expected by the Makefile;
- `test.rt`: example scene description, not yet loaded by the program.

## Current limitations

- The `.rt` file is not parsed yet: parameters are hard-coded in
  `TEMP_simulation`.
- Only sphere intersections are currently used by the rendering pipeline.
- Planes, cylinders, and shadows are represented in the project structures,
  but are not yet integrated into the rendering pipeline.
- The program does not process command-line arguments yet.

## Next step

The next step is to add an `.rt` file parser, then connect planes, cylinders,
and shadows to the existing renderer.
