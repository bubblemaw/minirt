/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:46:44 by maw               #+#    #+#             */
/*   Updated: 2025/06/14 14:36:16 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_plane(char *line, t_params *params)
{
	int i;
	int j;

	j = params->quantity.plane;
	params->plane = alloc_tab(params, PLANE);
	params->plane[j] = malloc (sizeof(t_plane));
	params->plane[j + 1] = NULL;
	i = 0;
	printf("line: %s\n", line);
	while (ft_isalpha(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (plane_view_point(line, &i, params->plane[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (plane_vector(line, &i, params->plane[j]) == FALSE)
		return (FALSE);	
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (plane_rgb(line, &i, params->plane[j]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int plane_view_point(char *line, int *i, t_plane *plane)
{
	if (put_position(i, &plane->pos.x, line) == FALSE)
		return (FALSE);
	if (put_position(i, &plane->pos.y, line) == FALSE)
		return (FALSE);
	if (put_position(i, &plane->pos.z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int plane_vector(char *line, int *i, t_plane *plane)
{
	if (put_vector(i, &plane->vector.a, line) == FALSE)
		return (FALSE);
	if (put_vector(i, &plane->vector.b, line) == FALSE)
		return (FALSE);
	if (put_vector(i, &plane->vector.c, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int plane_rgb(char *line, int *i, t_plane *plane)
{
	printf("enter rgb\n");
	if (put_rgb(i, &plane->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &plane->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &plane->color.b, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

