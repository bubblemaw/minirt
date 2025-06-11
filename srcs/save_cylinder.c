/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:40:50 by maw               #+#    #+#             */
/*   Updated: 2025/06/11 19:40:42 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_cylinder(char *line, t_params *params)
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
	if (cylinder_diameter(line, &i, params->cylinder[j]) == FALSE)
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
    if (cylinder->d < 0)
    {
        return (FALSE);
    }
	while (ft_isdigit_point(line[*i]))
		(*i)++;
    return (TRUE);
}

int cylinder_height(char *line, int *i, t_cylinder *cylinder)
{
    cylinder->h = ft_atof(line + (*i));
    if (cylinder->h < 0)
    {
        return (FALSE);
    }
	while (ft_isdigit_point(line[*i]))
		(*i)++;
    return (TRUE);
}

int cylinder_view_point(char *line, int *i, t_cylinder *cylinder)
{
	printf("cam view point\n");
	if (put_view_point(i, &cylinder->pos.x, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &cylinder->pos.y, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &cylinder->pos.z, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int cylinder_vector(char *line, int *i, t_cylinder *cylinder)
{
	printf("cam view point\n");
	if (put_view_point(i, &cylinder->vector.a, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &cylinder->vector.b, line) == FALSE)
		return (FALSE);
	if (put_view_point(i, &cylinder->vector.c, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int cylinder_rgb(char *line, int *i, t_cylinder *cylinder)
{
	printf("enter rgb\n");
	if (put_rgb(i, &cylinder->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &cylinder->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &cylinder->color.b, line) == FALSE)
		return (FALSE);
	return (TRUE);
}
