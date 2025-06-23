/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pattern.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hoannguy <hoannguy@student.42lausanne.c	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/23 22:01:37 by hoannguy		  #+#	#+#			 */
/*   Updated: 2025/06/23 23:09:00 by hoannguy		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	checkerboard_cylinder(t_params *params,
		t_vector hit_point, t_cylinder *cyl)
{
	float		angle;
	float		height;
	int			u;
	int			v;
	t_vector	center;

	center = vector_sub(hit_point, pos_to_vector(cyl->pos));
	angle = ((atan2(center.c + 0.0001f, center.a + 0.0001f)
				/ (2 * M_PI)) * params->checker.size);
	height = (center.b / params->checker.size);
	u = (int)floorf(angle) % 2;
	v = (int)floorf(height) % 2;
	if ((u + v) % 2 == 0)
		return (params->checker.color1);
	return (params->checker.color2);
}

t_color	checkerboard_sphere(t_params *params,
		t_vector hit_point, t_sphere *sphere)
{
	float		temp1;
	float		temp2;
	int			u;
	int			v;
	t_vector	center;

	center = vector_sub(hit_point, pos_to_vector(sphere->pos));
	temp1 = ((0.5 + atan2(center.c + 0.0001f, center.a + 0.0001f)
				/ (2 * M_PI)) * params->checker.size);
	temp2 = ((acos((center.b + 0.0001f) / (sphere->d / 2.0f))
				/ M_PI) * params->checker.size);
	u = (int)floorf(temp1) % 2;
	v = (int)floorf(temp2) % 2;
	if ((u + v) % 2 == 0)
		return (params->checker.color1);
	return (params->checker.color2);
}

t_color	checkerboard_plane(t_params *params, t_vector hit_point)
{
	float	temp1;
	float	temp2;
	int		u;
	int		v;

	temp1 = ((hit_point.a + 0.0001f) / params->checker.size);
	temp2 = ((hit_point.c + 0.0001f) / params->checker.size);
	u = (int)floorf(temp1) % 2;
	v = (int)floorf(temp2) % 2;
	if ((int)(u + v) % 2 == 0)
		return (params->checker.color1);
	return (params->checker.color2);
}

void	initialise_pattern(t_params *params)
{
	params->checker.size = 10;
	params->checker.color1.r = 255;
	params->checker.color1.g = 255;
	params->checker.color1.b = 255;
	params->checker.color2.r = 0;
	params->checker.color2.g = 0;
	params->checker.color2.b = 0;
	params->stripe.size = 50;
	params->stripe.color1.r = 255;
	params->stripe.color1.g = 255;
	params->stripe.color1.b = 0;
	params->stripe.color2.r = 0;
	params->stripe.color2.g = 255;
	params->stripe.color2.b = 255;
}
