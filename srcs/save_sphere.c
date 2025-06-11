/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:22:36 by maw               #+#    #+#             */
/*   Updated: 2025/06/11 19:40:14 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_sphere(char *line, t_params *params)
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
	if (sphere_view_point(line, &i, params->sphere[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	params->sphere[j]->d = atof(line + i);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (sphere_rgb(line, &i, params->sphere[j]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int sphere_view_point(char *line, int *i, t_sphere *sphere)
{
	printf("cam view point\n");
	if (put_view_point(i, &sphere->pos.x, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &sphere->pos.y, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &sphere->pos.z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int sphere_rgb(char *line, int *i, t_sphere *sphere)
{
	printf("enter rgb\n");
	if (put_rgb(i, &sphere->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &sphere->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &sphere->color.b, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

