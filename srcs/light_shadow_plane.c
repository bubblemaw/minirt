/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shadow_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:18:10 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/20 15:37:23 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	shadow_plane_check(t_params *params, t_ray *shadow,
		t_ray *ray, float light_dist)
{
	int			i;
	float		denom;
	float		t;
	t_vector	op;

	if (!params->plane)
		return (false);
	i = -1;
	while (params->plane[++i])
	{
		if (params->plane[i] == ray->hit_plane)
			continue ;
		// if (ray->hit_inside == true)
		// 	continue ;
		denom = vector_dot(shadow->direction, params->plane[i]->vector);
		if (denom < 0.000001f)
			continue ;
		op = vector_sub(pos_to_vector(params->plane[i]->pos), shadow->origin);
		t = vector_dot(op, params->plane[i]->vector) / denom;
		if (t > 0 && t * t < light_dist)
			return (true);
	}
	return (false);
}
