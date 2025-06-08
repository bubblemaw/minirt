/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:44:53 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/08 17:57:00 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
