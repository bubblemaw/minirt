/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:15:47 by masase            #+#    #+#             */
/*   Updated: 2025/06/14 19:54:42 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int parsing(char *file, t_params *params)
{
	if (check_arg(file) == FALSE)
		return (ft_error("file must finish by .rt"));
	if (read_scene(file, params) == FALSE)
		return (FALSE);
	return (TRUE);
}

int read_scene(char *file, t_params *params)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error("cant' open the file"));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line)
		{
			if (fill_struct(line, params) == TRUE)
			{
				free(line);
			}
			else 
			{
				free(line);
				get_next_line(-1);
				close(fd);
				return (FALSE);	
			}
		}
	}
	close(fd);
	return (TRUE);
}

int fill_struct(char *line, t_params *params)
{
	int i;

	i = 0;
	if (line[i])
	{
		while(ft_isspace(line[i]))
			i++;
		if(line[i] == 'A' && ft_isspace(line[i + 1]))
			return(save_ambiant(line, params));
		else if(line[i] == 'C' && ft_isspace(line[i + 1]))
			return(save_camera(line, params));		
		else if(line[i] == 'L' && ft_isspace(line[i + 1]))
			return(save_light(line, params));
		else if(line[i] == 's' && line[i + 1] == 'p' && ft_isspace(line[i + 2]))
			return(save_sphere(line, params));
		else if(line[i] == 'p' && line[i + 1] == 'l' && ft_isspace(line[i + 2]))
			return(save_plane(line, params));
		else if(line[i] == 'c' && line[i + 1] == 'y' && ft_isspace(line[i + 2]))
			return(save_cylinder(line, params));
		else if(line[i] == '\n' || line[i] == '\0')
			return(TRUE);
		else
			return (ft_error("Unknow identifiers"));
	}
	return(FALSE);
}


int	check_arg(char *str)
{
	int	len;

	if (!str)
		return (FALSE);
	len = ft_strlen(str);
	if (ft_strncmp(str + (len - 3), ".rt", 3) == 0)
		return (TRUE);
	return (FALSE);
}
