/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:09:12 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/08 22:31:22 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	camera_pos_up(t_params *params)
{
	params->camera.pos.y += 1;
	mlx_destroy_image(params->mlx, params->data.img);
	render(params);	
}

void	camera_pos_down(t_params *params)
{
	params->camera.pos.y -= 1;
	mlx_destroy_image(params->mlx, params->data.img);
	render(params);	
}

void	camera_pos_left(t_params *params)
{
	params->camera.pos.x -= 1;
	mlx_destroy_image(params->mlx, params->data.img);
	render(params);	
}

void	camera_pos_right(t_params *params)
{
	params->camera.pos.x += 1;
	mlx_destroy_image(params->mlx, params->data.img);
	render(params);	
}

void	camera_pos_forward(t_params *params)
{
	params->camera.pos.z += 1;
	mlx_destroy_image(params->mlx, params->data.img);
	render(params);	
}

