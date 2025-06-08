/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:17:12 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/08 11:52:25 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	my_mlx_pixel_put(t_params *params, int x, int y, int color[])
{
	char	*dest;

	if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
	{
		dest = params->data.addr + (x * params->data.line_length + y
				* (params->data.bits_per_pixel / 8));
		*(unsigned int *)dest = (color[0] << 16 | color[1] << 8 | color[2]);
	}
}

void	image_display(t_params *params)
{
	params->data.img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->data.addr = mlx_get_data_addr(params->data.img,
			&params->data.bits_per_pixel, &params->data.line_length,
			&params->data.endian);
	mlx_put_image_to_window(params->mlx,
		params->window, params->data.img, 0, 0);
}

int	render(t_params *params)
{
	params->mlx = mlx_init();
	params->window = mlx_new_window(params->mlx, WIDTH, HEIGHT,
			"I don't like math");
	hook(params);
	image_create(params);
	image_display(params);
	mlx_loop(params->mlx);
	return (0);
}
