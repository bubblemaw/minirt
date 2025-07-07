/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:38:09 by maw               #+#    #+#             */
/*   Updated: 2025/07/07 12:20:15 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float calculate_lateral_t_cone(t_cylinder *cone, t_ray *ray)
{
	t_inter_cone	t;
	float		t1;
	float		t2;	

	t.axis = cone->vector;
	vector_normalize(&t.axis);
	t.d_perp = vector_sub(ray->direction, vector_multi(vector_dot(ray->direction, t.axis), t.axis));
	t.oc = vector_sub(ray->origin, pos_to_vector(cone->pos));	
	t.oc_perp = vector_sub(t.oc, vector_multi(vector_dot(t.oc, t.axis), t.axis));
	t.a = vector_dot(t.d_perp, t.d_perp);
	t.c = vector_dot(t.oc_perp, t.oc_perp) - powf(cone->d / 2, 2);
	t.b = 2 * vector_dot(t.d_perp, t.oc_perp);
	t.disc = t.b * t.b - 4 * t.a * t.c;
	if (t.disc < 0)
		return (-1);
	t1 = (-t.b - sqrtf(t.disc)) / (2 * t.a);
	t2 = (-t.b + sqrtf(t.disc)) / (2 * t.a);	
	if (t2 < 0 )
		return (-1);
	if (t1 < t2 && height_projection(ray, cone, t1))
		return (t1);
	if (t2 < t1 && height_projection(ray, cone, t2))
		return (t2);
	return (-1);
}

void	intersection_cone(t_params *params, t_ray *ray)
{
	int			i;
	float		t_lateral;
	float		t_cap;
	t_vector	normal_cap;
	
	if (!params->cone)
		return ;
	t_lateral = -1;
	t_cap = -1;
	i = -1;
	while (params->cone[++i])
	{
		t_lateral = -1;
		t_cap = -1;
		t_lateral = calculate_lateral_t(params->cone[i], ray);
		t_cap = calculate_cap_t(params->cone[i], ray, &normal_cap);
		if (t_lateral > 0 && t_lateral < ray->t)
			set_t2_cylinder(params->cone[i], ray, t_lateral);	
		if (t_cap > 0 && t_cap < ray->t)
			set_t_cap(ray, t_cap, params->cone[i], normal_cap);
	}
}
