/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hoannguy <hoannguy@student.42lausanne.c	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/06 12:39:14 by masase			#+#	#+#			 */
/*   Updated: 2025/06/08 09:49:53 by hoannguy		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../inc/minirt.h"

void	TEMP_simulation(t_params *params)
{
	t_sphere	*sphere1;

	sphere1 = malloc(sizeof(t_sphere));
	sphere1->pos[0] = 0;
	sphere1->pos[1] = 1;
	sphere1->pos[2] = 5;
	sphere1->d = 1;
	sphere1->color[0] = 255;
	sphere1->color[1] = 255;
	sphere1->color[2] = 255;
	params->sphere = malloc(sizeof(t_sphere *) * 2);
	params->sphere[0] = sphere1;
	params->sphere[1] = NULL;

	params->camera.vector[0] = 0;
	params->camera.vector[1] = -0.2;
	params->camera.vector[2] = 1;
	params->camera.pos[0] = 0;
	params->camera.pos[1] = 4;
	params->camera.pos[2] = 0;
	params->camera.fov = 90;

	params->light = NULL;
	params->plane = NULL;
	params->cylinder = NULL;
}

int main(int ac,  char **av)
{
	(void)ac;
	(void)av;
	t_params	params;

	TEMP_simulation(&params);
	if (!render(&params))
	{
		mlx_destroy_image(params.mlx, params.data.img);
		mlx_destroy_window(params.mlx, params.window);
		return (free_all(&params), 1);
	}
	return(0);
}
