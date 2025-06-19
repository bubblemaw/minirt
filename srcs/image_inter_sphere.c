/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_inter_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:48:26 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/19 06:49:13 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	set_t2_sphere(t_sphere *sphere, t_ray *ray, float t2)
{
	t_vector	temp;

	ray->t = t2;
	ray->color = sphere->color;
	ray->hit_sphere = sphere;
	ray->hit_cylinder = NULL;
	ray->hit_plane = NULL;
	ray->hit_point = vector_add(ray->origin,
			vector_multi(t2, ray->direction));
	temp = pos_to_vector(sphere->pos);
	ray->normal = vector_sub(ray->hit_point, temp);
	if (vector_dot(ray->normal, ray->direction) > 0)
		vector_multi(-1.0f, ray->normal);
	vector_normalize(&ray->normal);
	ray->hit_point = vector_add(ray->hit_point,
			vector_multi(0.0001f, ray->normal));
}

// t1 is first hit. Normal is perpendicular vector to hitpoint.
// t2 is second hit.
void	set_t_sphere(t_sphere *sphere, t_ray *ray, float t1, float t2)
{
	t_vector	temp;

	if (t1 > 0 && t1 < ray->t)
	{
		ray->t = t1;
		ray->color = sphere->color;
		ray->hit_sphere = sphere;
		ray->hit_cylinder = NULL;
		ray->hit_plane = NULL;
		ray->hit_point = vector_add(ray->origin,
				vector_multi(t1, ray->direction));
		temp = pos_to_vector(sphere->pos);
		ray->normal = vector_sub(ray->hit_point, temp);
		vector_normalize(&ray->normal);
		ray->hit_point = vector_add(ray->hit_point,
				vector_multi(1e-4f, ray->normal));
	}
	else if (t2 > 0 && t2 < ray->t)
		set_t2_sphere(sphere, ray, t2);
}

// Quadratic equation: ||O + tD - C||² = r²
// Origin, Direction, Center, radius
// Plugin: t = -b ± √(b² - c)
void	intersection_sphere(t_params *params, t_ray *ray)
{
	int			i;
	float		b;
	float		t1;
	float		t2;
	t_vector	oc;

	if (!params->sphere)
		return ;
	i = -1;
	while (params->sphere[++i])
	{
		oc = vector_sub(ray->origin, pos_to_vector(params->sphere[i]->pos));
		b = 2 * vector_dot(ray->direction, oc);
		if ((b * b - 4 * (vector_dot(oc, oc)
					- pow((params->sphere[i]->d / 2), 2))) < 0)
			continue ;
		t1 = (-b - sqrtf(b * b - 4 * (vector_dot(oc, oc)
						- pow((params->sphere[i]->d / 2), 2)))) / 2;
		t2 = (-b + sqrtf(b * b - 4 * (vector_dot(oc, oc)
						- pow((params->sphere[i]->d / 2), 2)))) / 2;
		if (t2 < 0)
			continue ;
		set_t_sphere(params->sphere[i], ray, t1, t2);
	}
}
