/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:54:55 by masase            #+#    #+#             */
/*   Updated: 2025/06/14 19:21:16 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int put_rgb(int *i, int *value, char *line)
{
	if (line[*i] && ft_isdigit(line[*i]))
	{
		*value = ft_atoi(line + (*i));
	}
	else
		return (ft_error("RGB parameters have to be a number from 0 to 255"));
	if (*value < 0 || *value > 255)
		return (ft_error("RGB can set be set from 0 to 255"));
	while(ft_isdigit_point(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == ',')
		(*i)++;
	return (TRUE);
}

int put_vector(int *i, float *value, char *line)
{
	if (line[*i] && ft_isdigit_point(line[*i]))
	{
		*value = ft_atof(line + (*i));
	}
	else
		return (ft_error("Vector parameters have to be a number from -1 to 1"));	
	if (*value < -1 || *value > 1)
		return (ft_error("Vector can be set from -1 to 1"));
	while(ft_isdigit_point(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == ',')
		(*i)++;
	return (TRUE);
}

int put_position(int *i, float *value, char *line)
{
	if (line[*i] && ft_isdigit_point(line[*i]))
	{
		*value = ft_atof(line + (*i));
	}
	else
		return (ft_error("Position parameters have to be a number"));		
	while(ft_isdigit_point(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == ',')
		(*i)++;
	return (TRUE);
}
