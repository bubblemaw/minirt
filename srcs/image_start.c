/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:17:12 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/09 00:27:16 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_hit_point	**initialise_map(t_params *params)
{
	int	i;
	int	j;

	params->map = malloc(sizeof(t_hit_point *) * (HEIGHT + 1));
	if (params->map == NULL)
		return (perror("Error"), NULL);
	i = 0;
	while (i < HEIGHT)
	{
		params->map[i] = malloc(sizeof(t_hit_point) * WIDTH);
		if (params->map[i] == NULL)
			return (perror("Error"), free_map(params), NULL);
		j = 0;
		while (j < WIDTH)
		{
			params->map[i][j].hit = false;
			params->map[i][j].color.r = 0;
			params->map[i][j].color.g = 0;
			params->map[i][j].color.b = 0;
			j++;
		}
		i++;
	}
	params->map[i] = NULL;
	return (params->map);
}

void	my_mlx_pixel_put(t_params *params, int x, int y, t_color color)
{
	char	*dest;

	if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
	{
		dest = params->data.addr + (x * params->data.line_length + y
				* (params->data.bits_per_pixel / 8));
		*(unsigned int *)dest = (color.r << 16 | color.g << 8 | color.b);
	}
}

void	image_create(t_params *params)
{
	render_object(params);
	// render_light(params);
	// render_shadow(params);
}

void	image_display(t_params *params)
{
	params->data.img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->data.addr = mlx_get_data_addr(params->data.img,
			&params->data.bits_per_pixel, &params->data.line_length,
			&params->data.endian);
	image_create(params);
	mlx_put_image_to_window(params->mlx,
		params->window, params->data.img, 0, 0);
}

void	render(t_params *params)
{
	hook(params);
	image_display(params);
	mlx_loop(params->mlx);
}
