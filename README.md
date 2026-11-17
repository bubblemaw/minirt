# miniRT

`miniRT` is a C ray tracer built with MiniLibX. It reads a scene description
from a `.rt` file, traces one ray per pixel, and renders the result in a
`1920x1080` window.

## Features

- Parsing of `.rt` scene files.
- Perspective camera with configurable position, direction, and field of view.
- Multiple point lights and one ambient light.
- Ray intersections with:
  - spheres;
  - planes;
  - finite cylinders, including caps;
  - finite cones, including caps.
- Ambient, diffuse, and specular lighting.
- Shadows cast by scene objects.
- Checkerboard and stripe patterns.
- Planet textures for spheres: Earth, Mars, Mercury, Pluto, and Venus.
- Bump mapping for planet textures.
- Interactive camera movement and orientation.
- Error handling for invalid file extensions, identifiers, values, and
  arguments.

## Requirements

- Linux with X11.
- A C compiler.
- `make`.
- MiniLibX Linux available in `minilibx-linux/`.
- X11, Xext, and math libraries.

## Build and run

```bash
make
./miniRT scene/test6.2.rt
```

The program requires a scene file ending in `.rt`. Several example scenes are
available in the [`scene/`](scene/) directory.

### Make targets

```bash
make        # Build miniRT and its dependencies
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Rebuild everything
```

## Scene file format

Each non-empty line starts with an identifier:

| Identifier | Format |
| ---------- | ------ |
| `A` | `A ambient_ratio R,G,B` |
| `C` | `C x,y,z nx,ny,nz fov` |
| `L` | `L x,y,z brightness R,G,B` |
| `sp` | `sp x,y,z diameter R,G,B shine texture` |
| `pl` | `pl x,y,z nx,ny,nz R,G,B texture` |
| `cy` | `cy x,y,z nx,ny,nz diameter height R,G,B shine texture` |
| `co` | `co x,y,z nx,ny,nz diameter height R,G,B shine texture` |

Positions accept floating-point values. Direction vectors must have
components between `-1` and `1`. RGB components must be between `0` and `255`.
Ambient and light brightness values must be between `0.0` and `1.0`, while the
camera field of view must be between `0` and `180`.

Example:

```text
C 0,-5,-50 0,0.2,1 60
L 60,10,-50 1 255,255,255
L -60,10,-50 1 255,255,255
A 0.6 0,0,0

sp 0,5,0 25 255,100,100 30 3
pl 0,-30,0 0,1,0 255,255,255 0
```

### Texture selectors

The last value on an object line selects its texture or pattern:

| Value | Texture |
| ----- | ------- |
| `0` | Solid object color |
| `1` | Checkerboard |
| `2` | Stripes |
| `3` | Earth |
| `4` | Mars |
| `5` | Mercury |
| `6` | Pluto |
| `7` | Venus |

The texture assets and their bump maps are stored in [`srcs/maps/`](srcs/maps/).

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
| `Escape` | Close the window |

## Project structure

- [`inc/minirt.h`](inc/minirt.h): shared structures, constants, and prototypes.
- [`srcs/parsing/`](srcs/parsing/): scene file parser and object creation.
- [`srcs/inter_*.c`](srcs/): ray intersections for supported primitives.
- [`srcs/light_*.c`](srcs/): ambient, diffuse, and specular lighting.
- [`srcs/shadow*.c`](srcs/): shadow calculations.
- [`srcs/pattern_*.c`](srcs/): procedural and planet textures.
- [`srcs/maps/`](srcs/maps/): texture and bump-map assets.
- [`gnl/`](gnl/): `get_next_line` used by the parser.
- [`libft/`](libft/): project utility library.

## Current limitations

- The renderer depends on MiniLibX Linux and X11.
- Rendering is performed on the CPU and can take time for large scenes.
- Texture values from `8` to `12` are accepted by the parser, but the
  visible object texture selectors currently cover `0` to `7`.
