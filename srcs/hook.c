/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:41:26 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/08 12:12:05 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	key_press(int keycode, t_params *params)
{
	if (keycode == ESC_KEY)
		x_close_window(params);
	return (0);
}

int	x_close_window(t_params *params)
{
	free_all(params);
	mlx_destroy_image(params->mlx, params->data.img);
	mlx_destroy_window(params->mlx, params->window);
	printf("Program terminated\n");
	exit(0);
}

void	hook(t_params *params)
{
	mlx_hook(params -> window, 2, 1L << 0, key_press, params);
	mlx_hook(params -> window, 33, 1L << 0, x_close_window, params);
}
