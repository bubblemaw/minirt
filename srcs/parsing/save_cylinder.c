/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:40:50 by maw               #+#    #+#             */
/*   Updated: 2025/06/14 19:20:26 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int save_cylinder(char *line, t_params *params)
{
	int i;
	int j;

	i = 0;
	j = params->quantity.cylinder;
	params->cylinder = alloc_tab(params, CYLINDER);
	params->cylinder[j] = malloc (sizeof(t_cylinder));
	params->cylinder[j + 1] = NULL;
	while (ft_isalpha(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (cylinder_view_point(line, &i, params->cylinder[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (cylinder_vector(line, &i, params->cylinder[j]) == FALSE)
		return (FALSE);	
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (cylinder_diameter(line, &i, params->cylinder[j]) == FALSE)
		return (FALSE);
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (cylinder_height(line, &i, params->cylinder[j]) == FALSE)
		return (FALSE);
	while (ft_isspace(line[i]) && line[i])
		i++;	
	if (cylinder_rgb(line, &i, params->cylinder[j]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int cylinder_diameter(char *line, int *i, t_cylinder *cylinder)
{
    cylinder->d = ft_atof(line + (*i));
    if (cylinder->d <= 0)
		return(ft_error("Cylinder diameter have to be bigger than 0"));
	while (ft_isdigit_point(line[*i]))
		(*i)++;
    return (TRUE);
}

int cylinder_height(char *line, int *i, t_cylinder *cylinder)
{
    cylinder->h = ft_atof(line + (*i));
    if (cylinder->h <= 0)
		return(ft_error("Cylinder height have to be bigger than 0"));
	while (ft_isdigit_point(line[*i]))
		(*i)++;
    return (TRUE);
}

int cylinder_view_point(char *line, int *i, t_cylinder *cylinder)
{
	if (put_position(i, &cylinder->pos.x, line) == FALSE)
		return (FALSE);
	if (put_position(i, &cylinder->pos.y, line) == FALSE)
		return (FALSE);
	if (put_position(i, &cylinder->pos.z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int cylinder_vector(char *line, int *i, t_cylinder *cylinder)
{
	if (put_vector(i, &cylinder->vector.a, line) == FALSE)
		return (FALSE);
	if (put_vector(i, &cylinder->vector.b, line) == FALSE)
		return (FALSE);
	if (put_vector(i, &cylinder->vector.c, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int cylinder_rgb(char *line, int *i, t_cylinder *cylinder)
{
	if (put_rgb(i, &cylinder->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &cylinder->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &cylinder->color.b, line) == FALSE)
		return (FALSE);
	return (TRUE);
}
