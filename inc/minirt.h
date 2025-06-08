/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:05:52 by masase            #+#    #+#             */
/*   Updated: 2025/06/08 17:09:49 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include "../libft/libft.h" 
# include "../minilibx-linux/mlx.h"

# define ESC_KEY 65307

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

// PARSING ---------------------------------


// IMAGE -----------------------------------
int			render(t_params *params);
void		render_object(t_params *params);
void		my_mlx_pixel_put(t_params *params, int x, int y, t_color color);

// RAYON -----------------------------------


// LIGHT -----------------------------------


// SHADOW ----------------------------------


// UTIL ------------------------------------
void		free_all(t_params *params);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_multi(float x, t_vector v1);
t_vector	vector_divi(t_vector v1, float x);
float		vector_dot(t_vector v1, t_vector v2);
float		vector_norm2(t_vector v1);
void		vector_normalize(t_vector *v1);
t_vector	pos_to_vector(t_pos pos);

// HOOk ------------------------------------
void		hook(t_params *params);
int			x_close_window(t_params *params);

#endif 
