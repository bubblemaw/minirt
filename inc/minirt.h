/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:05:52 by masase            #+#    #+#             */
/*   Updated: 2025/06/10 13:41:55 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <float.h>
# include <stdbool.h>
# include "../libft/libft.h" 
# include "../minilibx-linux/mlx.h"

# define ESC_KEY 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define Q 113
# define E 101
# define T 116
# define G 103
# define F 102
# define H 104
# define R 114

# define HEIGHT 720
# define WIDTH 1080

// BASE PIECE STRUCT -----------------------
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vector
{
	float	a;
	float	b;
	float	c;
}	t_vector;

typedef struct	s_pos
{
	float	x;
	float	y;
	float	z;
}	t_pos;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

// SCENE ITEM STRUCT -----------------------
typedef struct	s_camera
{
	t_vector	vector;
	t_pos		pos;
	int			fov;
}	t_camera;

typedef struct	s_light
{
	t_pos	pos;
	t_color	color;
	float	ratio;
}	t_light;

typedef struct	s_ambient
{
	float	ratio;
	t_color	color;
}	t_ambient;

typedef struct	s_plane
{
	t_vector	vector;
	t_pos		pos;
	t_color	color;
}	t_plane;

typedef struct	s_cylinder
{
	t_vector	vector;
	t_pos		pos;
	t_color		color;
	float		d;
	float		h;
}	t_cylinder;

typedef struct	s_sphere
{
	t_pos	pos;
	t_color	color;
	float	d;
}	t_sphere;

// MAIN STRUCT -----------------------------
typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
	t_color		color;
	float		t;
	t_vector	hit_point;
	t_vector	normal;
	t_plane		*hit_plane;
	t_cylinder	*hit_cylinder;
	t_sphere	*hit_sphere;
}	t_ray;

typedef struct	s_params
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		**light;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_sphere	**sphere;
	void		*mlx;
	void		*window;
	t_data		data;
}	t_params;

// SAVE LINE -------------------------------
typedef struct	s_pixel
{
	int			i;
	int			j;
	t_vector	horiz;
	t_vector	vert;
}	t_pixel;

typedef	struct	s_world
{
	float		aspect_ratio;
	float		fov_rad;
	t_vector	right;
	t_vector	up;
	t_vector	forward;
	t_vector	world_up;
}	t_world;

// PARSING ---------------------------------


// IMAGE -----------------------------------
void		render(t_params *params);
void		render_object(t_params *params);
void		my_mlx_pixel_put(t_params *params, int x, int y, t_color color);

// RAYON -----------------------------------
void	intersection_sphere(t_params *params, t_ray *ray);

// LIGHT -----------------------------------


// SHADOW ----------------------------------


// UTIL ------------------------------------
void		free_all(t_params *params);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_multi(float x, t_vector v1);
t_vector	vector_divi(t_vector v1, float x);
t_vector	vector_cross(t_vector v1, t_vector v2);
float		vector_dot(t_vector v1, t_vector v2);
float		vector_norm2(t_vector v1);
void		vector_normalize(t_vector *v1);
t_vector	pos_to_vector(t_pos pos);

// HOOk ------------------------------------
void		hook(t_params *params);
int			x_close_window(t_params *params);
void		camera_pos_forward(t_params *params);
void		camera_pos_backward(t_params *params);
void		camera_pos_left(t_params *params);
void		camera_pos_right(t_params *params);
void		camera_pos_up(t_params *params);
void		camera_pos_down(t_params *params);
void		camera_look_up(t_params *params);
void		camera_look_down(t_params *params);
void		camera_look_left(t_params *params);
void		camera_look_right(t_params *params);

#endif 
