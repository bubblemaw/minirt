/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:48:26 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/09 10:56:46 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	set_default_color(t_ray *ray)
{
	ray->color.r = 0;
	ray->color.g = 0;
	ray->color.b = 0;
}

void	intersection_sphere(t_params *params, t_ray *ray)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	float		t1_curr;
	float		t2_curr;
	t_vector	oc;
	t_vector	v_sphere;

	if (!params->sphere)
		return ;
	a = 1;
	// t1_prev = FLT_MAX;
	// t2_prev = FLT_MAX;
	// i = -1;
	// while (params->sphere[++i])
	v_sphere = pos_to_vector(params->sphere[0]->pos);
	oc = vector_sub(ray->origin, v_sphere);
	b = 2 * vector_dot(ray->direction, oc);
	c = vector_dot(oc, oc) - pow((params->sphere[0]->d / 2), 2);
	delta = b * b - 4 * c * a;
	if (delta < 0)
		return (set_default_color(ray));
	t1_curr = (-b - sqrtf(delta)) / 2;
	t2_curr = (-b + sqrtf(delta)) / 2;
	if (t1_curr > 0 || t2_curr > 0)
		ray->color = params->sphere[0]->color;
}

void	intersection(t_params *params, t_ray *ray)
{
	ray->origin = pos_to_vector(params->camera.pos);
	intersection_sphere(params, ray);
}

void	initialise_values(t_params *params, t_world *world)
{
	world->world_up.a = 0;
	world->world_up.b = 1;
	world->world_up.c = 0;
	world->forward = params->camera.vector;
	vector_normalize(&world->forward);
	world->right = vector_cross(world->world_up, world->forward);
	vector_normalize(&world->right);
	world->up = vector_cross(world->forward, world->right);
	world->aspect_ratio = (float)WIDTH / HEIGHT;
	world->fov_rad = tan((params->camera.fov * M_PI / 180.0f) / 2.0f);
}

void	render_object(t_params *params)
{
	t_pixel	pixel;
	t_world	world;
	t_ray	ray;

	initialise_values(params, &world);
	pixel.i = -1;
	while (++pixel.i < HEIGHT)
	{
		pixel.j = -1;
		while (++pixel.j < WIDTH)
		{
			pixel.horiz = vector_multi((2 * ((pixel.j + 0.5f) / WIDTH) - 1)
					* world.aspect_ratio * world.fov_rad, world.right);
			pixel.vert = vector_multi((1 - 2 * ((pixel.i + 0.5f) / HEIGHT))
					* world.fov_rad, world.up);
			ray.direction = vector_add(world.forward, vector_add(pixel.horiz, pixel.vert));
			vector_normalize(&ray.direction);
			intersection(params, &ray);
			my_mlx_pixel_put(params, pixel.i, pixel.j, ray.color);
		}
	}
}
