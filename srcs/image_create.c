/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:48:26 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/15 19:15:54 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	intersection(t_params *params, t_ray *ray)
{
	intersection_sphere(params, ray);
	calculate_ambient_light(params, ray);
	calculate_diffuse_light(params, ray);
	ray->color = color_add(ray->ambient, ray->diffuse);
}

// Setup camera direction based on camera vector.
// world_up is the world orientation vector.
// forward is axe z, right is axe x and up is axe y for camera vector.
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

void	initialise_ray(t_params *params, t_ray *ray)
{
	ray->origin = pos_to_vector(params->camera.pos);
	ray->color.r = 0;
	ray->color.g = 0;
	ray->color.b = 0;
	ray->t = FLT_MAX;
	ray->hit_plane = NULL;
	ray->hit_cylinder = NULL;
	ray->hit_sphere = NULL;
	ray->diffuse.r = 0;
	ray->diffuse.g = 0;
	ray->diffuse.b = 0;
}

// pixel.horiz shifts the ray horizontally
// pixel.vert shifts the ray vetically
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
			initialise_ray(params, &ray);
			pixel.horiz = vector_multi((2 * ((pixel.j + 0.5f) / WIDTH) - 1)
					* world.aspect_ratio * world.fov_rad, world.right);
			pixel.vert = vector_multi((1 - 2 * ((pixel.i + 0.5f) / HEIGHT))
					* world.fov_rad, world.up);
			ray.direction = vector_add(world.forward,
					vector_add(pixel.horiz, pixel.vert));
			vector_normalize(&ray.direction);
			intersection(params, &ray);
			my_mlx_pixel_put(params, pixel.i, pixel.j, ray.color);
		}
	}
}
