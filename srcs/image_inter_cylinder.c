/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_inter_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:59:56 by maw               #+#    #+#             */
/*   Updated: 2025/06/27 14:09:06 by maw              ###   ########.fr       */
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
	t_vector	from_base;
	float		height_projection;

	if (t1 > 0 && t1 < ray->t)
	{
		ray->t = t1;
		ray->color = cylinder->color;
		ray->hit_sphere = NULL;
		ray->hit_cylinder = cylinder;
		ray->hit_plane = NULL;
		ray->hit_point = vector_add(ray->origin,
				vector_multi(t1, ray->direction));
		from_base = vector_sub(ray->hit_point, cylinder->vector);
		height_projection = vector_dot(from_base, cylinder->inter.axis);
		
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
	float		height_projection;
	t_vector	oc;
	t_vector	d_perp;
	t_vector	oc_perp;	
	t_vector	axis;
	t_cylinder **cy_tab;


	if (!params->cylinder)
		return ;
	cy_tab = params->cylinder;		
	i = -1;
	while (cy_tab[++i])
	{
		cy_tab[i]->inter.axis = cy_tab[i]->vector;
		vector_normalize(&cy_tab[i]->inter.axis);
		cy_tab[i]->inter.d_perp = vector_sub(ray->direction, vector_multi(vector_dot(ray->direction, cy_tab[i]->inter.axis), cy_tab[i]->inter.axis));
		cy_tab[i]->inter.oc = vector_sub(ray->origin, pos_to_vector(cy_tab[i]->pos));	
		cy_tab[i]->inter.oc_perp = vector_sub(cy_tab[i]->inter.oc, vector_multi(vector_dot(cy_tab[i]->inter.oc, cy_tab[i]->inter.axis), cy_tab[i]->inter.axis));
		cy_tab[i]->inter.a = vector_dot(cy_tab[i]->inter.d_perp, cy_tab[i]->inter.d_perp);
		cy_tab[i]->inter.c = vector_dot(cy_tab[i]->inter.oc_perp, cy_tab[i]->inter.oc_perp) - powf(params->cylinder[i]->d / 2, 2);
		cy_tab[i]->inter.b = 2 * vector_dot(cy_tab[i]->inter.d_perp, cy_tab[i]->inter.oc_perp);
		cy_tab[i]->inter.disc = cy_tab[i]->inter.b * cy_tab[i]->inter.b - 4 * cy_tab[i]->inter.a * cy_tab[i]->inter.c;
		if (cy_tab[i]->inter.disc < 0)
			continue ;
		t1 = (-cy_tab[i]->inter.b - sqrtf(cy_tab[i]->inter.disc)) / (2 * cy_tab[i]->inter.a);
		t2 = (-cy_tab[i]->inter.b + sqrtf(cy_tab[i]->inter.disc)) / (2 * cy_tab[i]->inter.a);
		if (t2 < 0)
			continue ;
		set_t_cylinder(cy_tab[i], ray, t1, t2);
	}
}
