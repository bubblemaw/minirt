/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:48:26 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/08 18:49:12 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	intersection(t_params *params, t_vector direction, t_color *color)
{
	float		b;
	float		c;
	float		delta;
	float		t1;
	float		t2;
	t_vector	v_camera;
	t_vector	v_sphere;

	v_camera = pos_to_vector(params->camera.pos);
	v_sphere = pos_to_vector(params->sphere[0]->pos);
	b = 2 * vector_dot(direction, vector_sub(v_camera, v_sphere));
	c = vector_norm2(vector_sub(v_camera, v_sphere))
		- (params->sphere[0]->d / 2) * (params->sphere[0]->d / 2);
	delta = b * b - 4 * c;
	if (delta < 0)
	{
		(*color).r = 0;
		(*color).g = 0;
		(*color).b = 0;
		return ;
	}
	t1 = (-1 * b - sqrt(delta)) / 2;
	t2 = (-1 * b + sqrt(delta)) / 2;
	if (t1 > 0)
		*color = params->sphere[0]->color;
	else if (t2 > 0)
		*color = params->sphere[0]->color;
}

void	render_object(t_params *params)
{
	int			i;
	int			j;
	t_vector	direction;
	t_color		color;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			direction.a = j - WIDTH / 2;
			direction.b = i - HEIGHT / 2;
			direction.c = (WIDTH
					/ (2 * tan(((params->camera.fov * M_PI / 180) / 2))));
			vector_normalize(&direction);
			intersection(params, direction, &color);
			my_mlx_pixel_put(params, i, j, color);
			j++;
		}
		i++;
	}
}
