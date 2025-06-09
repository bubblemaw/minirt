/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:05:52 by masase            #+#    #+#             */
/*   Updated: 2025/06/09 19:34:00 by masase           ###   ########.fr       */
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

typedef struct s_camera
{
    int number;
    float x;
    float y;
    float z;
    float v_x;
    float v_y;
    float v_z;
    int FOV;
}t_camera;

typedef struct s_plane
{
    int number;
    float x;
    float y;
    float z;
    float v_x;
    float v_y;
    float v_z;
    int R;
    int G;
    int B;
}t_plane;

typedef struct s_sphere
{
    int number;
    float x;
    float y;
    float z;
    float diameter;
    int R;
    int G;
    int B;
}t_sphere;

typedef struct s_cylinder
{
    int number;
    float x;
    float y;
    float z;
    float v_x;
    float v_y;
    float v_z;
    int R;
    int G;
    int B;
    float diameter;
    float height;

}t_cylinder;

typedef struct s_light
{

}t_light;

typedef struct s_ambiance
{
    int number;
    int R;
    int G;
    int B;
    float ratio;
}t_ambiance;

typedef struct s_point
{
    int number;
    float x;
    float y;
    float z;
    float bright_ratio;

}t_point;

// typedef struct s_object
// {
//     t_plane;
//     t_sphere;
//     t_cylinder;
// }t_object;

typedef struct s_scene
{
    t_camera camera;
    t_plane plane;
    t_sphere sphere;
    t_cylinder cy;
    t_ambiance amb;
    t_point point;
        
}t_scene;

int error(char *str);


int	check_arg(char *str);
int save_ambiant(char *line, t_scene *scene);
int fill_struct(char *line, t_scene *scene);
int read_scene(char *file, t_scene *scene);
int parsing(char *file, t_scene *scene);
int amb_rgb(char *line, int *i, t_ambiance *ambiance);
int put_rgb(int *i, int *value, char *line);
int	ft_isdigit_point(int c);
int save_camera(char *line, t_scene *scene);


//utils
int	ft_isspace(int c);
float	ft_atof(const char *str);
void decimal_atof(int i, const char *str, float *resultat);

#endif
