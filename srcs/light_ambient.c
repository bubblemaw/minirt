/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:26:07 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/25 02:04:48 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	get_sphere_color(t_params *params, t_ray *ray, t_color *color)
{
	t_color	temp;

	if (ray->hit_sphere->texture_type == CHECKER)
		temp = checkerboard_sphere(params, ray->hit_point, ray->hit_sphere);
	else if (ray->hit_sphere->texture_type == STRIPE)
		temp = stripe_sphere(params, ray->hit_point, ray->hit_sphere);
	else if (ray->hit_sphere->texture_type == EARTH)
		temp = planet_sphere(params, ray->hit_point, ray->hit_sphere, EARTH);
	else if (ray->hit_sphere->texture_type == MARS)
		temp = planet_sphere(params, ray->hit_point, ray->hit_sphere, MARS);
	else if (ray->hit_sphere->texture_type == MERCU)
		temp = planet_sphere(params, ray->hit_point, ray->hit_sphere, MERCU);
	else if (ray->hit_sphere->texture_type == PLUTO)
		temp = planet_sphere(params, ray->hit_point, ray->hit_sphere, PLUTO);
	else if (ray->hit_sphere->texture_type == VENUS)
		temp = planet_sphere(params, ray->hit_point, ray->hit_sphere, VENUS);
	else
		temp = ray->hit_sphere->color;
	color->r = temp.r;
	color->g = temp.g;
	color->b = temp.b;
	return ;
}

void	get_cylinder_color(t_params *params, t_ray *ray, t_color *color)
{
	t_color	temp;

	if (ray->hit_cylinder->texture_type == CHECKER)
		temp = checkerboard_cylinder(params,
				ray->hit_point, ray->hit_cylinder);
	else if (ray->hit_cylinder->texture_type == STRIPE)
		temp = stripe_cylinder(params,
				ray->hit_point, ray->hit_cylinder);
	else
		temp = ray->hit_cylinder->color;
	color->r = temp.r;
	color->g = temp.g;
	color->b = temp.b;
	return ;
}

void	get_plane_color(t_params *params, t_ray *ray, t_color *color)
{
	t_color	temp;

	if (ray->hit_plane->texture_type == CHECKER)
		temp = checkerboard_plane(params, ray->hit_point);
	else if (ray->hit_plane->texture_type == STRIPE)
		temp = stripe_plane(params, ray->hit_point);
	else
		temp = ray->hit_plane->color;
	color->r = temp.r;
	color->g = temp.g;
	color->b = temp.b;
	return ;
}

// formula is object color * ambient ratio * (ambient color / 255)
void	calculate_ambient_light(t_params *params, t_ray *ray)
{
	t_color	color;

	if (ray->hit_sphere != NULL)
		get_sphere_color(params, ray, &color);
	else if (ray->hit_cylinder != NULL)
		get_cylinder_color(params, ray, &color);
	else if (ray->hit_plane != NULL)
		get_plane_color(params, ray, &color);
	else
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
	ray->ambient.r = color.r * params->ambient.ratio
		* (params->ambient.color.r / 255.0f);
	ray->ambient.g = color.g * params->ambient.ratio
		* (params->ambient.color.g / 255.0f);
	ray->ambient.b = color.b * params->ambient.ratio
		* (params->ambient.color.b / 255.0f);
}
