/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:47:20 by maw               #+#    #+#             */
/*   Updated: 2025/06/14 14:37:53 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_light(char *line, t_params *params)
{
	int i;
	int j;

	j = params->quantity.light;
	params->light = alloc_tab(params, LIGHT);
	params->light[j] = malloc (sizeof(t_light));
	params->light[j + 1] = NULL;
	i = 0;
	printf("line: %s\n", line);
	while (ft_isalpha(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (light_view_point(line, &i, params->light[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (light_ratio(line, &i, params->light[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (light_rgb(line, &i, params->light[j]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int light_ratio(char *line, int *i, t_light *light)
{
	light->ratio = atof(line + (*i));
    if (light->ratio < 0 || light->ratio > 1)
    {
        return (ft_error("Light ratio can be set from 0.0 to 1.0"));
    }
	while (ft_isdigit_point(line[*i]))
		(*i)++;
    return (TRUE);
}

int light_view_point(char *line, int *i, t_light *light)
{
	if (put_position(i, &light->pos.x, line) == FALSE)
		return (FALSE);
	if (put_position(i, &light->pos.y, line) == FALSE)
		return (FALSE);
	if (put_position(i, &light->pos.z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int light_rgb(char *line, int *i, t_light *light)
{
	if (put_rgb(i, &light->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &light->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &light->color.b, line) == FALSE)
		return (FALSE);
	return (TRUE);
}
