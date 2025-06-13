/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ambiance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:06:32 by masase            #+#    #+#             */
/*   Updated: 2025/06/13 16:34:05 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_ambiant(char *line, t_params *params)
{
	int i;

	i = 0;
	printf("save ambiant\n");
	printf("line: %s\n", line);
	while (ft_isalpha(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;


	while (ft_isdigit_point(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (amb_rgb(line, &i, &params->ambient) == FALSE)
		return (FALSE);
	return (TRUE);
}

int amb_ratio(char *line, int *i, t_ambient *ambient)
{
	if ((line[*i] && ft_isdigit(line[*i])) || line[*i] == '.')
		ambient->ratio = ft_atof(line + (*i));
	if (ambient->ratio < 0 || ambient->ratio > 1)
		return (ft_error("Ambient ratio can be set from 0.0 to 1.0"));
	return (TRUE);
}

int amb_rgb(char *line, int *i, t_ambient *ambient)
{
	printf("enter rgb\n");
	if (put_rgb(i, &ambient->color.r, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &ambient->color.g, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &ambient->color.b, line) == FALSE)
		return (FALSE);
	return (TRUE);
}
