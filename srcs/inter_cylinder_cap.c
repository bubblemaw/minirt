/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder_cap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:03:24 by maw               #+#    #+#             */
/*   Updated: 2025/06/28 18:31:18 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void set_t_cap(t_ray *ray, float t, t_cylinder *cylinder, t_vector normal)
{
	ray->t = t;
	ray->hit_cylinder = cylinder;
	ray->hit_plane = NULL;
	ray->hit_sphere = NULL;
	ray->color = cylinder->color;
	ray->normal = normal;
	ray->hit_point = vector_add(ray->origin, vector_multi(t, ray->direction));
	ray->hit_point = vector_add(ray->hit_point, vector_multi(1e-4f, normal));
}

int touch_under_cap(t_vector axis, t_ray *ray, t_cylinder *cylinder)
{
	float denom;
	float t;
	t_vector base;
	
	base = pos_to_vector(cylinder->pos);
	denom = vector_dot(ray->direction, axis);
	if (fabs(denom) < 1e-6)
		return (0);
	t = vector_dot(vector_sub(base, ray->origin), axis) / denom;
	if (t < 0 || t > ray->t)
		return (0);
	ray->hit_point = vector_add(ray->origin, vector_multi(t, ray->direction));
	if (vector_lenght(vector_sub(ray->hit_point, base)) > cylinder->d / 2)
		return (0);
	set_t_cap(ray, t, cylinder, vector_multi(-1, axis));
	return (1);
}

int touch_top_cap(t_vector axis, t_ray *ray, t_cylinder *cylinder)
{
	float denom;
	float t;
	t_vector base;
	
	base = vector_add(pos_to_vector(cylinder->pos), vector_multi(cylinder->h, axis));
	denom = vector_dot(ray->direction, axis);
	if (fabs(denom) < 1e-6)
		return (0);
	t = vector_dot(vector_sub(base, ray->origin), axis) / denom;
	if (t < 0 || t > ray->t)
		return (0);
	ray->hit_point = vector_add(ray->origin, vector_multi(t, ray->direction));
	if (vector_lenght(vector_sub(ray->hit_point, base)) > cylinder->d / 2)
		return (0);
	set_t_cap(ray, t, cylinder, axis);
	return (1);
}

void intersection_cylinder_cap(t_params *params, t_ray *ray)
{
	int i;
	t_vector axis;

	if (!params->cylinder)
		return;
	i = -1;
	while (params->cylinder[++i])
	{
		axis = params->cylinder[i]->vector;
		vector_normalize(&axis);		
		touch_under_cap(axis, ray, params->cylinder[i]);
		touch_top_cap(axis, ray, params->cylinder[i]);		
	}
}
