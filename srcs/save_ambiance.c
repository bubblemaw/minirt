/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ambiance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:06:32 by masase            #+#    #+#             */
/*   Updated: 2025/06/12 15:56:50 by masase           ###   ########.fr       */
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
	if ((line[i] && isdigit(line[i])) || line[i] == '.')
		params->ambient.ratio = ft_atof(line + i);
	while (ft_isdigit_point(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (amb_rgb(line, &i, &params->ambient) == FALSE)
		return (FALSE);
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
