/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:46:44 by maw               #+#    #+#             */
/*   Updated: 2025/06/11 19:39:55 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_plane(char *line, t_params *params)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
	printf("cam view point\n");
	if (put_view_point(i, &plane->pos.x, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &plane->pos.y, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &plane->pos.z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int plane_vector(char *line, int *i, t_plane *plane)
{
	printf("cam view point\n");
	if (put_view_point(i, &plane->vector.a, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &plane->vector.b, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &plane->vector.c, line) == FALSE)
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

