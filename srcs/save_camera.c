/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:06:25 by masase            #+#    #+#             */
/*   Updated: 2025/06/10 12:56:17 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_camera(char *line, t_scene *scene)
{
	int i;

	i = 0;
	printf("line: %s\n", line);
	while (ft_isalpha(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (cam_view_point(line, &i, &scene->camera) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (cam_vector(line, &i, &scene->camera) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
    if (save_fov(line, &i, &scene->camera) == FALSE)
    {
        return (FALSE);
    }
	return (TRUE);
}

int save_fov(char *line, int *i, t_camera *camera)
{
    camera->FOV = atoi(line + (*i));
    if (camera->FOV < 0 || camera->FOV > 180)
    {
        return (FALSE);
    }
    return (TRUE);
}

int cam_view_point(char *line, int *i, t_camera *camera)
{
	printf("cam view point\n");
	if (put_view_point(i, &camera->x, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &camera->y, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &camera->z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int put_view_point(int *i, float *value, char *line)
{
	if (line[*i] && ft_isdigit_point(line[*i]))
	{
		*value = ft_atof(line + (*i));
		printf("value: %f\n", *value);
	}
	while(ft_isdigit_point(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == ',')
		(*i)++;
	return (TRUE);
}

int cam_vector(char *line, int *i, t_camera *camera)
{
	printf("enter rgb\n");
	if (put_view_point(i, &camera->v_x, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &camera->v_y, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &camera->v_z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}


