/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:51:53 by masase            #+#    #+#             */
/*   Updated: 2025/07/07 12:04:41 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int save_cone(char *line, t_params *params)
{
	int i;
	int j;

	i = 0;
	j = params->quantity.cone;
	params->cone = alloc_tab(params, CONE);
	params->cone[j] = malloc (sizeof(t_cone));
	params->cone[j + 1] = NULL;
	while (ft_isalpha(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (cone_view_point(line, &i, params->cone[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (cone_vector(line, &i, params->cone[j]) == FALSE)
		return (FALSE);	
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (cone_diameter(line, &i, params->cone[j]) == FALSE)
		return (FALSE);
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (cone_height(line, &i, params->cone[j]) == FALSE)
		return (FALSE);
	while (ft_isspace(line[i]) && line[i])
		i++;	
	if (cone_rgb(line, &i, params->cone[j]) == FALSE)
		return (FALSE);
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (save_shine(&i, &params->cone[j]->shine, line) == FALSE)
		return (FALSE);
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (save_texture(&i, &params->cone[j]->texture_type, line) == FALSE)
		return (FALSE);
	if (ft_isprint(line[i]))
		return (ft_error("Too much arguments for the cone RGB parameters"));
	return (TRUE);
}

int cone_diameter(char *line, int *i, t_cone *cone)
{
    cone->d = ft_atof(line + (*i));
    if (cone->d <= 0)
		return(ft_error("Cone diameter have to be number bigger than 0"));
	while (ft_isdigit_point(line[*i]))
		(*i)++;
	if (!ft_isspace(line[*i]))
		return (ft_error("there is too much cone diameter arguments"));		
    return (TRUE);
}

int cone_height(char *line, int *i, t_cone *cone)
{
    cone->h = ft_atof(line + (*i));
    if (cone->h <= 0)
		return(ft_error("Cone height have to be a number bigger than 0"));
	while (ft_isdigit_point(line[*i]))
		(*i)++;
	if (!ft_isspace(line[*i]))
		return (ft_error("there is too much cone height arguments"));
    return (TRUE);
}

int cone_view_point(char *line, int *i, t_cone *cone)
{
	if (put_position(i, &cone->pos.x, line) == FALSE)
		return (FALSE);
	if (put_position(i, &cone->pos.y, line) == FALSE)
		return (FALSE);
	if (put_position(i, &cone->pos.z, line) == FALSE)
		return (FALSE);
	if (!ft_isspace(line[*i]))
		return (ft_error("Too much arguments for the position parameters"));		
	return (TRUE);
}

int cone_vector(char *line, int *i, t_cone *cone)
{
	if (put_vector(i, &cone->vector.a, line) == FALSE)
		return (FALSE);
	if (put_vector(i, &cone->vector.b, line) == FALSE)
		return (FALSE);
	if (put_vector(i, &cone->vector.c, line) == FALSE)
		return (FALSE);
	if (!ft_isspace(line[*i]))
		return (ft_error("Too much arguments for the vector parameters"));		
	return (TRUE);
}

int cone_rgb(char *line, int *i, t_cone *cone)
{
	if (put_rgb(i, &cone->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &cone->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &cone->color.b, line) == FALSE)
		return (FALSE);		
	return (TRUE);
}
