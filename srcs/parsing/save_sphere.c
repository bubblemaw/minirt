/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:22:36 by maw               #+#    #+#             */
/*   Updated: 2025/06/14 19:20:58 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int save_sphere(char *line, t_params *params)
{
	int i;
	int j;

	j = params->quantity.sphere;
	params->sphere = alloc_tab(params, SPHERE);
	params->sphere[j] = malloc (sizeof(t_sphere));
	params->sphere[j + 1] = NULL;
	i = 0;
	while (ft_isalpha(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (sphere_view_point(line, &i, params->sphere[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (sphere_diameter(line, &i, params->sphere[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (sphere_rgb(line, &i, params->sphere[j]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int sphere_diameter(char *line, int *i, t_sphere *sphere)
{
	sphere->d = atof(line + (*i));
	if (sphere->d <= 0)
		return(ft_error("Sphere diameter have to be bigger than 0"));
	while (ft_isdigit_point(line[*i]))
		(*i)++;
    return (TRUE);
}

int sphere_view_point(char *line, int *i, t_sphere *sphere)
{
	if (put_position(i, &sphere->pos.x, line) == FALSE)
		return (FALSE);
	if (put_position(i, &sphere->pos.y, line) == FALSE)
		return (FALSE);
	if (put_position(i, &sphere->pos.z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int sphere_rgb(char *line, int *i, t_sphere *sphere)
{
	if (put_rgb(i, &sphere->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &sphere->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &sphere->color.b, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

