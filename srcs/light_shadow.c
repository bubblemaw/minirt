/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:46:02 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/18 19:53:58 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	initialise_shadow_ray(t_ray *ray, t_ray *shadow)
{
	shadow->origin = vector_add(ray->hit_point,
			vector_multi(0.0001f, ray->normal));
	shadow->color.r = 0;
	shadow->color.g = 0;
	shadow->color.b = 0;
	shadow->t = FLT_MAX;
	shadow->hit_plane = NULL;
	shadow->hit_cylinder = NULL;
	shadow->hit_sphere = NULL;
}

bool	shadow_sphere_check(t_params *params, t_ray *shadow,
		t_ray *ray, float light_dist)
{
	int			i;
	float		d;
	float		t1;
	float		t2;
	t_vector	oc;

	if (!params->sphere)
		return (false);
	i = -1;
	while (params->sphere[++i])
	{
		if (params->sphere[i] == ray->hit_sphere)
			continue ;
		oc = vector_sub(shadow->origin, pos_to_vector(params->sphere[i]->pos));
		d = pow(2 * vector_dot(shadow->direction, oc), 2)
			- 4 * (vector_dot(oc, oc) - pow(params->sphere[i]->d / 2, 2));
		if (d < 0)
			continue ;
		t1 = (-(2 * vector_dot(shadow->direction, oc)) - sqrtf(d)) / 2.0f;
		t2 = (-(2 * vector_dot(shadow->direction, oc)) + sqrtf(d)) / 2.0f;
		if ((t1 > 0 && t1 * t1 < light_dist)
			|| (t2 > 0 && t2 * t2 < light_dist))
			return (true);
	}
	return (false);
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
	if (shadow_sphere_check(params, &shadow, ray, light_dist))
		return (true);
	// if (shadow_plane_check(...))
	// 	return (true);
	// if (shadow_cylinder_check(...))
	//     return (true);
	return (false);
}

// bool	shadow_sphere_check(t_params *params, t_ray *shadow, t_ray *ray)
// {
// 	int			i;
// 	float		b;
// 	float		discriminant;
// 	t_vector	oc;

// 	if (!params->sphere)
// 		return (false);
// 	i = -1;
// 	while (params->sphere[++i])
// 	{
// 		if (params->sphere[i] == ray->hit_sphere)
// 			continue ;
// 		oc = vector_sub(shadow->origin, pos_to_vector(params->sphere[i]->pos));
// 		b = 2 * vector_dot(shadow->direction, oc);
// 		discriminant = b * b - 4 * (vector_dot(oc, oc)
// 				- pow(params->sphere[i]->d / 2, 2));
// 		if (discriminant < 0)
// 			continue ;
// 		discriminant = sqrtf(discriminant);
// 		if (((-b - discriminant) / 2) > 0 && ((-b - discriminant) / 2) < 1.0f)
// 			return (true);
// 		if (((-b + discriminant) / 2) > 0 && ((-b + discriminant) / 2) < 1.0f)
// 			return (true);
// 	}
// 	return (false);
// }

// bool	shadow_check(t_params *params, t_ray *ray, t_vector *hit_light)
// {
// 	t_ray	shadow;

// 	shadow.direction = *hit_light;
// 	initialise_shadow_ray(ray, &shadow);
// 	if (shadow_sphere_check(params, &shadow, ray) == true)
// 		return (true);
// 	// if (shadow_plane_check(params, &shadow) == true)
// 	// 	return (true);
// 	// if (shadow_cylinder_check(params, &shadow) == true)
// 	// 	return (true);
// 	return (false);
// }