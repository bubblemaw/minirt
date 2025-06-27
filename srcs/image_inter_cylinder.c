/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_inter_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:59:56 by maw               #+#    #+#             */
/*   Updated: 2025/06/25 17:21:48 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	set_t2_cylinder(t_cylinder *cylinder, t_ray *ray, float t2)
{
	t_vector	temp;

	ray->t = t2;
	ray->color = cylinder->color;
	ray->hit_sphere = NULL;
	ray->hit_cylinder = cylinder;
	ray->hit_plane = NULL;
	ray->hit_point = vector_add(ray->origin,
			vector_multi(t2, ray->direction));
	temp = pos_to_vector(cylinder->pos);
	ray->normal = vector_sub(ray->hit_point, temp);
	if (vector_dot(ray->normal, ray->direction) > 0)
		ray->normal = vector_multi(-1.0f, ray->normal);
	vector_normalize(&ray->normal);
	ray->hit_point = vector_add(ray->hit_point,
			vector_multi(0.0001f, ray->normal));
}

// t1 is first hit. Normal is perpendicular vector to hitpoint.
// t2 is second hit.
void	set_t_cylinder(t_cylinder *cylinder, t_ray *ray, float t1, float t2)
{
	t_vector	temp;

	if (t1 > 0 && t1 < ray->t)
	{
		ray->t = t1;
		ray->color = cylinder->color;
		ray->hit_sphere = NULL;
		ray->hit_cylinder = cylinder;
		ray->hit_plane = NULL;
		ray->hit_point = vector_add(ray->origin,
				vector_multi(t1, ray->direction));
		temp = pos_to_vector(cylinder->pos);
		ray->normal = vector_sub(ray->hit_point, temp);
		vector_normalize(&ray->normal);
		ray->hit_point = vector_add(ray->hit_point,
				vector_multi(1e-4f, ray->normal));
	}
	else if (t2 > 0 && t2 < ray->t)
		set_t2_cylinder(cylinder, ray, t2);
}

//At2 + Bt + C = 0

void	intersection_cylinder(t_params *params, t_ray *ray)
{
	int			i;
	float		b;
	float		a;
	float		c;
	float		disc;
	float		t1;
	float		t2;
	t_vector	oc;
	t_vector	d_perp;
	t_vector	oc_perp;	
	t_vector	axis;

	if (!params->cylinder)
		return ;
	i = -1;
	while (params->cylinder[++i])
	{
		axis = params->cylinder[i]->vector;
		vector_normalize(&axis);
		d_perp = vector_sub(ray->direction, vector_multi(vector_dot(ray->direction, axis), axis));
		oc = vector_sub(ray->origin, pos_to_vector(params->cylinder[i]->pos));	
		oc_perp = vector_sub(oc, vector_multi(vector_dot(oc, axis), axis));
		a = vector_dot(d_perp, d_perp);
		c = vector_dot(oc_perp, oc_perp) - powf(params->cylinder[i]->d / 2, 2);
		b = 2 * vector_dot(d_perp, oc_perp);			
		// a = powf(ray->direction.a, 2) + powf(ray->direction.c, 2);		
		// c = powf(oc.a, 2) + powf(oc.c, 2) - powf(params->cylinder[i]->d / 2, 2);
		// b = 2 * oc.a * ray->direction.a + 2 * oc.c * ray->direction.c;
		disc = b * b - 4 * a *c;
		if (disc < 0)
			continue ;
		t1 = (-b - sqrtf(disc)) / (2 * a);
		t2 = (-b + sqrtf(disc)) / (2 * a);
		if (t2 < 0)
			continue ;
		set_t_cylinder(params->cylinder[i], ray, t1, t2);
	}
}
