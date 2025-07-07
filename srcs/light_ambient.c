/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:26:07 by hoannguy          #+#    #+#             */
/*   Updated: 2025/07/07 17:58:57 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
	else if (ray->hit_cone != NULL)
		get_cone_color(params, ray, &color);
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
