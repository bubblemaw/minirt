/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_inter_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:59:56 by maw               #+#    #+#             */
/*   Updated: 2025/06/22 19:43:06 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


void	set_t2_cylinder(t_sphere *cylinder, t_ray *ray, float t2)
{
	t_vector	temp;

	ray->t = t2;
	ray->color = cylinder->color;
	ray->hit_sphere = cylinder;
	ray->hit_cylinder = NULL;
	ray->hit_plane = NULL;
	ray->hit_point = vector_add(ray->origin,
			vector_multi(t2, ray->direction));
	temp = pos_to_vector(cylinder->pos);
	ray->normal = vector_sub(ray->hit_point, temp);
	if (vector_dot(ray->normal, ray->direction) > 0)
		vector_multi(-1.0f, ray->normal);
	vector_normalize(&ray->normal);
	ray->hit_point = vector_add(ray->hit_point,
			vector_multi(0.0001f, ray->normal));
}

// t1 is first hit. Normal is perpendicular vector to hitpoint.
// t2 is second hit.
void	set_t_cylinder(t_sphere *cylinder, t_ray *ray, float t1, float t2)
{
	t_vector	temp;

	if (t1 > 0 && t1 < ray->t)
	{
		ray->t = t1;
		ray->color = cylinder->color;
		ray->hit_sphere = cylinder;
		ray->hit_cylinder = NULL;
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
		set_t2_sphere(cylinder, ray, t2);
}

//At2 + Bt + C = 0

void	intersection_cylinder(t_params *params, t_ray *ray)
{
	int			i;
	float		b;
	float		t1;
	float		t2;
	t_vector	oc;

	if (!params->cylinder)
		return ;
	i = -1;
	while (params->cylinder[++i])
	{
		oc = vector_sub(ray->origin, pos_to_vector(params->cylinder[i]->pos));
		b = 2 * ray->direction.a * ray->direction.a + 2 * ray->direction.c * ray->direction.c;
		if ((b * b - 4 * (vector_dot(oc, oc)
					- powf((params->cylinder[i]->d / 2), 2))) < 0)
			continue ;
		t1 = (-b - sqrtf(b * b - 4 * (vector_dot(oc, oc)
						- powf((params->cylinder[i]->d / 2), 2)))) / 2;
		t2 = (-b + sqrtf(b * b - 4 * (vector_dot(oc, oc)
						- powf((params->cylinder[i]->d / 2), 2)))) / 2;
		if (t2 < 0)
			continue ;
		set_t_sphere(params->cylinder[i], ray, t1, t2);
	}
}
