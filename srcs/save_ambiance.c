/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ambiance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:06:32 by masase            #+#    #+#             */
/*   Updated: 2025/06/10 12:07:44 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int save_ambiant(char *line, t_scene *scene)
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
		scene->amb.ratio = ft_atof(line + i);
	while (ft_isdigit_point(line[i]) && line[i])
		i++;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (amb_rgb(line, &i, &scene->amb) == FALSE)
		return (FALSE);
	return (TRUE);
}

int amb_rgb(char *line, int *i, t_ambiance *ambiance)
{
	printf("enter rgb\n");
	if (put_rgb(i, &ambiance->R, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &ambiance->G, line) == FALSE)
		return (FALSE);
	if (put_rgb(i, &ambiance->B, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

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

