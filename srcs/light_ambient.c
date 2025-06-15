/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:26:07 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/15 16:10:57 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	get_color(int *r, int *g, int *b, t_ray *ray)
{
	if (ray->hit_sphere != NULL)
	{
		*r = ray->hit_sphere->color.r;
		*g = ray->hit_sphere->color.g;
		*b = ray->hit_sphere->color.b;
	}
	else if (ray->hit_cylinder != NULL)
	{
		*r = ray->hit_cylinder->color.r;
		*g = ray->hit_cylinder->color.g;
		*b = ray->hit_cylinder->color.b;
	}
	else if (ray->hit_plane != NULL)
	{
		*r = ray->hit_plane->color.r;
		*g = ray->hit_plane->color.g;
		*b = ray->hit_plane->color.b;
	}
	else
	{
		*r = 0;
		*g = 0;
		*b = 0;
	}
}

void	calculate_ambient_light(t_params *params, t_ray *ray)
{
	int	r;
	int	g;
	int	b;

	get_color(&r, &g, &b, ray);
	ray->ambient.r = r * params->ambient.ratio
		* (params->ambient.color.r / 255.0f);
	ray->ambient.g = g * params->ambient.ratio
		* (params->ambient.color.g / 255.0f);
	ray->ambient.b = b * params->ambient.ratio
		* (params->ambient.color.b / 255.0f);
}
