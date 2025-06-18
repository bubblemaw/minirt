/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:06:25 by masase            #+#    #+#             */
/*   Updated: 2025/06/15 13:14:08 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int save_camera(char *line, t_params *params)
{
	int i;

	i = 0;
	while (ft_isalpha(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (cam_view_point(line, &i, &params->camera) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (cam_vector(line, &i, &params->camera) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
    if (save_fov(line, &i, &params->camera) == FALSE)
    {
        return (FALSE);
    }
	return (TRUE);
}

int save_fov(char *line, int *i, t_camera *camera)
{
    camera->fov = atoi(line + (*i));
    if (camera->fov < 0 || camera->fov > 180)
    {
        return (ft_error("FOV can be set from 0 to 180"));
    }
	while (ft_isdigit(line[*i]))
		(*i)++;
	if (!ft_isspace(line[*i]))
		return (ft_error("there is too much FOV arguments"));
    return (TRUE);
}

int cam_view_point(char *line, int *i, t_camera *camera)
{
	if (put_position(i, &camera->pos.x, line) == FALSE)
		return (FALSE);
	if (put_position(i, &camera->pos.y, line) == FALSE)
		return (FALSE);
	if (put_position(i, &camera->pos.z, line) == FALSE)
		return (FALSE);
	if (!ft_isspace(line[*i]))
		return (ft_error("Too much arguments for the position parameters"));
	return (TRUE);
}

int cam_vector(char *line, int *i, t_camera *camera)
{
	if (put_vector(i, &camera->vector.a, line) == FALSE)
		return (FALSE);
	if (put_vector(i, &camera->vector.b, line) == FALSE)
		return (FALSE);
	if (put_vector(i, &camera->vector.c, line) == FALSE)
		return (FALSE);
	if (!ft_isspace(line[*i]))
		return (ft_error("Too much arguments for the vector parameters"));		
	return (TRUE);
}
