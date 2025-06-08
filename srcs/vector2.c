/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:44:53 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/08 19:09:46 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vector	vector_cross(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.a = v1.b * v2.c - v1.c * v2.b;
	v3.b = v1.c * v2.a - v1.a * v2.c;
	v3.c = v1.a * v2.b - v1.b * v2.a;
	return (v3);
}

float	vector_norm2(t_vector v1)
{
	float	x;

	x = v1.a * v1.a + v1.b * v1.b + v1.c * v1.c;
	return (x);
}

void	vector_normalize(t_vector *v1)
{
	float	norm;

	norm = sqrt(vector_norm2(*v1));
	if (norm == 0.0f)
		return ;
	v1->a /= norm;
	v1->b /= norm;
	v1->c /= norm;
}

t_vector	pos_to_vector(t_pos pos)
{
	t_vector	v;

	v.a = pos.x;
	v.b = pos.y;
	v.c = pos.z;
	return (v);
}
