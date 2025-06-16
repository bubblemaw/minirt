/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:46:02 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/16 19:40:43 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	shadow_sphere_check(t_params *params, t_ray *shadow)
{
	int			i;
	float		b;
	float		discriminant;
	t_vector	oc;

	if (!params->sphere)
		return (false);
	i = -1;
	while (params->sphere[++i])
	{
		oc = vector_sub(shadow->origin, pos_to_vector(params->sphere[i]->pos));
		b = 2 * vector_dot(shadow->direction, oc);
		discriminant = b * b - 4 * (vector_dot(oc, oc)
				- pow(params->sphere[i]->d / 2, 2));
		if (discriminant < 0)
			continue ;
		discriminant = sqrtf(discriminant);
		if (((-b - discriminant) / 2) > 0 && ((-b - discriminant) / 2) < 1.0f)
			return (true);
		if (((-b + discriminant) / 2) > 0 && ((-b + discriminant) / 2) < 1.0f)
			return (true);
	}
	return (false);
}

void	initialise_shadow_ray(t_ray *ray, t_ray *shadow)
{
	shadow->origin = vector_add(ray->hit_point,
			vector_multi(0.001f, ray->normal));
	shadow->color.r = 0;
	shadow->color.g = 0;
	shadow->color.b = 0;
	shadow->t = FLT_MAX;
	shadow->hit_plane = NULL;
	shadow->hit_cylinder = NULL;
	shadow->hit_sphere = NULL;
}

bool	shadow_check(t_params *params, t_ray *ray, t_vector *hit_light)
{
	t_ray	shadow;

	shadow.direction = *hit_light;
	initialise_shadow_ray(ray, &shadow);
	if (shadow_sphere_check(params, &shadow) == true)
		return (true);
	// if (shadow_plane_check(params, &shadow) == true)
	// 	return (true);
	// if (shadow_cylinder_check(params, &shadow) == true)
	// 	return (true);
	return (false);
}
