/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:47:20 by maw               #+#    #+#             */
/*   Updated: 2025/06/11 19:41:17 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_light(char *line, t_params *params)
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
	if (light_view_point(line, &i, params->light[j]) == FALSE)
		return (FALSE);
    while (ft_isspace(line[i]) && line[i])
		i++;
	params->light[j]->ratio = atof(line + i);
    while (ft_isspace(line[i]) && line[i])
		i++;
	if (light_rgb(line, &i, params->light[j]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int light_view_point(char *line, int *i, t_light *light)
{
	printf("cam view point\n");
	if (put_view_point(i, &light->pos.x, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &light->pos.y, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &light->pos.z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int light_rgb(char *line, int *i, t_light *light)
{
	printf("enter rgb\n");
	if (put_rgb(i, &light->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &light->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &light->color.b, line) == FALSE)
		return (FALSE);
	return (TRUE);
}
