/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_inter_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:59:56 by maw               #+#    #+#             */
/*   Updated: 2025/06/21 12:38:17 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
		b = 2 * vector_dot(ray->direction, oc);
		if ((b * b - 4 * (vector_dot(oc, oc)
					- pow((params->cylinder[i]->d / 2), 2))) < 0)
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
