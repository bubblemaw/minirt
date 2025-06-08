/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:05:52 by masase            #+#    #+#             */
/*   Updated: 2025/06/08 11:52:30 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h" 
# include "../minilibx-linux/mlx.h"

# define ESC_KEY 65307

# define HEIGHT 720
# define WIDTH 1080
# define M_PI 3.1459

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// SCENE ITEM STRUCT -----------------------
typedef struct	s_camera
{
	float	vector[3];
	float	pos[3];
	int		fov;
}	t_camera;

typedef struct	s_light
{
	float	pos[3];
	int		color[3];
	float	ratio;
}	t_light;

typedef struct	s_ambient
{
	float	ratio;
	int		color[3];
}	t_ambient;

typedef struct	s_plane
{
	float	vector[3];
	float	pos[3];
	int		color[3];
}	t_plane;

typedef struct	s_cylinder
{
	float	vector[3];
	float	pos[3];
	int		color[3];
	float	d;
	float	h;
}	t_cylinder;

typedef struct	s_sphere
{
	float	pos[3];
	int		color[3];
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
int		render(t_params *params);
void	image_create(t_params *params);
void	my_mlx_pixel_put(t_params *params, int x, int y, int color[]);

// RAYON -----------------------------------


// LIGHT -----------------------------------


// SHADOW ----------------------------------


// UTIL ------------------------------------
void	free_all(t_params *params);

// HOOk ------------------------------------
void	hook(t_params *params);
int		x_close_window(t_params *params);

#endif 
