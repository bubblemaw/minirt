/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:46:02 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/20 15:18:58 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	initialise_shadow_ray(t_ray *ray, t_ray *shadow)
{
	t_vector	offset;

	if (ray->hit_inside)
		offset = vector_multi(-0.001f, ray->normal);
	else
		offset = vector_multi(0.001f, ray->normal);
	shadow->origin = vector_add(ray->hit_point, offset);
	shadow->color.r = 0;
	shadow->color.g = 0;
	shadow->color.b = 0;
	shadow->t = FLT_MAX;
	shadow->hit_plane = NULL;
	shadow->hit_cylinder = NULL;
	shadow->hit_sphere = NULL;
}

bool	shadow_check(t_params *params, t_ray *ray,
	t_vector *hit_light, int index)
{
	t_ray		shadow;
	t_vector	light_pos;
	t_vector	light_vec;
	float		light_dist;

	shadow.direction = *hit_light;
	initialise_shadow_ray(ray, &shadow);
	light_pos = pos_to_vector(params->light[index]->pos);
	light_vec = vector_sub(light_pos, ray->hit_point);
	light_dist = vector_dot(light_vec, light_vec);
	if (shadow_sphere_check(params, &shadow, light_dist,
			pos_to_vector(params->light[index]->pos)))
		return (true);
	if (shadow_plane_check(params, &shadow, ray, light_dist))
		return (true);
	// if (shadow_cylinder_check(...))
	//     return (true);
	return (false);
}
