/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:59:56 by maw               #+#    #+#             */
/*   Updated: 2025/06/28 16:38:55 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	set_t2_cylinder(t_cylinder *cylinder, t_ray *ray, float t2)
{
	t_vector	temp;
	t_vector	from_base;
	float		height_projection;
	t_vector	axis;
	
	axis = cylinder->vector;
	vector_normalize (&axis);
	ray->hit_point = vector_add(ray->origin,
			vector_multi(t2, ray->direction));
	from_base = vector_sub(ray->hit_point, pos_to_vector(cylinder->pos));
	height_projection = vector_dot(from_base, axis);
	if (height_projection < 0 || height_projection > cylinder->h)
	{
		ray->hit_cylinder = NULL;
		return ;
	}
	ray->t = t2;
	ray->color = cylinder->color;
	ray->hit_sphere = NULL;
	ray->hit_cylinder = cylinder;
	ray->hit_plane = NULL;
	temp = vector_sub(ray->hit_point, pos_to_vector(cylinder->pos));
	ray->normal = vector_sub(temp, vector_multi(vector_dot(temp, axis), axis));
	vector_normalize(&ray->normal);
	ray->hit_point = vector_add(ray->hit_point,
			vector_multi(1e-4f, ray->normal));
}

// t1 is first hit. Normal is perpendicular vector to hitpoint.
// t2 is second hit.
void	set_t_cylinder(t_cylinder *cylinder, t_ray *ray, float t1, float t2)
{
	t_vector	temp;
	t_vector	from_base;
	float		height_projection;
	t_vector	axis;

	axis = cylinder->vector;
	vector_normalize (&axis);
	if (t1 > 0 && t1 < ray->t)
	{
		ray->hit_point = vector_add(ray->origin,
				vector_multi(t1, ray->direction));
		from_base = vector_sub(ray->hit_point, pos_to_vector(cylinder->pos));
		height_projection = vector_dot(from_base, axis);
		if (height_projection < 0 || height_projection > cylinder->h)
		{
			ray->hit_cylinder = NULL;
			return ;	
		}
		ray->t = t1;
		ray->color = cylinder->color;
		ray->hit_sphere = NULL;
		ray->hit_cylinder = cylinder;
		ray->hit_plane = NULL;
		temp = vector_sub(ray->hit_point, pos_to_vector(cylinder->pos));
		ray->normal = vector_sub(temp, vector_multi(vector_dot(temp, axis), axis));
		vector_normalize(&ray->normal);
		ray->hit_point = vector_add(ray->hit_point,
				vector_multi(1e-4f, ray->normal));
	}
	else if (t2 > 0 && t2 < ray->t)
		set_t2_cylinder(cylinder, ray, t2);
}

void	intersection_cylinder(t_params *params, t_ray *ray)
{
	int			i;
	float		t1;
	float		t2;
	t_inter		t;
	
	if (!params->cylinder)
		return ;		
	i = -1;
	while (params->cylinder[++i])
	{
		t.axis = params->cylinder[i]->vector;
		vector_normalize(&t.axis);
		t.d_perp = vector_sub(ray->direction, vector_multi(vector_dot(ray->direction, t.axis), t.axis));
		t.oc = vector_sub(ray->origin, pos_to_vector(params->cylinder[i]->pos));	
		t.oc_perp = vector_sub(t.oc, vector_multi(vector_dot(t.oc, t.axis), t.axis));
		t.a = vector_dot(t.d_perp, t.d_perp);
		t.c = vector_dot(t.oc_perp, t.oc_perp) - powf(params->cylinder[i]->d / 2, 2);
		t.b = 2 * vector_dot(t.d_perp, t.oc_perp);
		t.disc = t.b * t.b - 4 * t.a * t.c;
		if (t.disc < 0)
			continue ;
		t1 = (-t.b - sqrtf(t.disc)) / (2 * t.a);
		t2 = (-t.b + sqrtf(t.disc)) / (2 * t.a);	
		if (t2 < 0)
			continue ;
		set_t_cylinder(params->cylinder[i], ray, t1, t2);
	}
}


