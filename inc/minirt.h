/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:05:52 by masase            #+#    #+#             */
/*   Updated: 2025/06/12 17:53:18 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h" 
# include "../gnl/get_next_line.h" 
# include <fcntl.h>

enum
{
    FALSE,
    TRUE,
};

typedef enum
{
    LIGHT,
    PLANE,
	CYLINDER,
	SPHERE,
}	e_tab_type;

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

typedef struct s_quantity
{
	int	light;
	int plane;
	int	cylinder;
	int	sphere;
}	t_quantity;

typedef struct	s_params
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		**light;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_sphere	**sphere;
	t_quantity	quantity;
	void		*mlx;
	void		*window;
	t_data		data;
}	t_params;

typedef struct s_scene
{
    t_camera camera;
    t_plane plane;
    t_sphere sphere;
    t_cylinder cy;
    t_ambient amb;
    t_light point;
        
}t_scene;

int error(char *str);


int	check_arg(char *str);

int fill_struct(char *line, t_params *params);
int read_scene(char *file, t_params *params);
int parsing(char *file, t_params *params);
int	ft_isdigit_point(int c);

//save utils
int put_rgb(int *i, int *value, char *line);
int put_view_point(int *i, float *value, char *line);

//save camera
int save_camera(char *line, t_params *params);
int save_fov(char *line, int *i, t_camera *camera);
int cam_view_point(char *line, int *i, t_camera *camera);
int cam_vector(char *line, int *i, t_camera *camera);

// save ambient
int save_ambiant(char *line, t_params *params);
int amb_rgb(char *line, int *i, t_ambient *ambiance);

// save light
int save_light(char *line, t_params *params);
int light_view_point(char *line, int *i, t_light *light);
int light_rgb(char *line, int *i, t_light *light);
int light_ratio(char *line, int *i, t_light *light);

// save sphere
int save_sphere(char *line, t_params *params);
int sphere_view_point(char *line, int *i, t_sphere *sphere);
int sphere_rgb(char *line, int *i, t_sphere *sphere);
int sphere_diameter(char *line, int *i, t_sphere *sphere);

// save plane
int save_plane(char *line, t_params *params);
int plane_vector(char *line, int *i, t_plane *plane);
int plane_view_point(char *line, int *i, t_plane *plane);
int plane_rgb(char *line, int *i, t_plane *plane);

// save cylinder
int save_cylinder(char *line, t_params *params);
int cylinder_diameter(char *line, int *i, t_cylinder *cylinder);
int cylinder_height(char *line, int *i, t_cylinder *cylinder);
int cylinder_view_point(char *line, int *i, t_cylinder *cylinder);
int cylinder_vector(char *line, int *i, t_cylinder *cylinder);
int cylinder_rgb(char *line, int *i, t_cylinder *cylinder);

//utils
int	ft_isspace(int c);
float	ft_atof(const char *str);
void decimal_atof(int i, const char *str, float *resultat);

//utils 2
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	*alloc_tab(t_params *params, e_tab_type type);

//printf
void print_camera_as_array(t_camera *cam);
void print_plane_as_array(t_plane *plane);
void print_sphere_as_array(t_sphere *sp);
void print_cylinder_as_array(t_cylinder *cyl);
void print_ambiance_as_array(t_ambient *amb);
void print_point_as_array(t_light *light);

#endif
