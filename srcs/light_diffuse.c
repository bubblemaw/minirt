/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   light_diffuse.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hoannguy <hoannguy@student.42lausanne.c	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/15 17:34:59 by hoannguy		  #+#	#+#			 */
/*   Updated: 2025/06/15 19:36:21 by hoannguy		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../inc/minirt.h"

void	all_diffuse(t_params *params, t_ray *ray,
		t_color *diffuse_total, t_color *object_color)
{
	int			i;
	t_vector	hit_light;

	i = -1;
	while (params->light[++i] != NULL)
	{
		hit_light = vector_sub(pos_to_vector(params->light[i]->pos),
				ray->hit_point);
		vector_normalize(&hit_light);
		if (vector_dot(ray->normal, hit_light) <= 0)
			continue ;
		diffuse_total->r += object_color->r * params->light[i]->color.r
			/ 255.0f * vector_dot(ray->normal, hit_light)
			* params->light[i]->ratio;
		diffuse_total->g += object_color->g * params->light[i]->color.g
			/ 255.0f * vector_dot(ray->normal, hit_light)
			* params->light[i]->ratio;
		diffuse_total->b += object_color->b * params->light[i]->color.b
			/ 255.0f * vector_dot(ray->normal, hit_light)
			* params->light[i]->ratio;
	}
}

// formula is 
// object color * light color * light ratio * (surface normal . hitToLight vector)
void	calculate_diffuse_light(t_params *params, t_ray *ray)
{
	t_color	object_color;
	t_color	diffuse_total;

	if (!ray->hit_sphere && !ray->hit_cylinder && !ray->hit_plane)
		return ;
	if (ray->hit_sphere)
		object_color = ray->hit_sphere->color;
	else if (ray->hit_cylinder)
		object_color = ray->hit_cylinder->color;
	else if (ray->hit_plane)
		object_color = ray->hit_plane->color;
	diffuse_total.r = 0;
	diffuse_total.g = 0;
	diffuse_total.b = 0;
	all_diffuse(params, ray, &diffuse_total, &object_color);
	ray->diffuse.r = (int)diffuse_total.r;
	ray->diffuse.g = (int)diffuse_total.g;
	ray->diffuse.b = (int)diffuse_total.b;
	if (ray->diffuse.r > 255)
		ray->diffuse.r = 255;
	if (ray->diffuse.g > 255)
		ray->diffuse.g = 255;
	if (ray->diffuse.b > 255)
		ray->diffuse.b = 255;
}
