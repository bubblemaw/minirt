/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:54:55 by masase            #+#    #+#             */
/*   Updated: 2025/06/12 16:03:21 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int put_rgb(int *i, int *value, char *line)
{
	if (line[*i] && ft_isdigit(line[*i]))
	{
		*value = ft_atoi(line + (*i));
		printf("value: %d\n", *value);
	}
	if (*value < 0 || *value > 255)
		return (FALSE);
	while(ft_isdigit_point(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == ',')
		(*i)++;
	else
		return(FALSE);
	return (TRUE);
}

int put_view_point(int *i, float *value, char *line)
{
	if (line[*i] && ft_isdigit_point(line[*i]))
	{
		*value = ft_atof(line + (*i));
		printf("value: %f\n", *value);
	}
	while(ft_isdigit_point(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == ',')
		(*i)++;
	return (TRUE);
}
