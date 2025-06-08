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
	sphere1->pos.x = 0;
	sphere1->pos.y = 0;
	sphere1->pos.z = 0;
	sphere1->d = 5;
	sphere1->color.r = 255;
	sphere1->color.g = 0;
	sphere1->color.b = 0;
	params->sphere = malloc(sizeof(t_sphere *) * 2);
	params->sphere[0] = sphere1;
	params->sphere[1] = NULL;

	params->camera.vector.a = 0;
	params->camera.vector.b = 0;
	params->camera.vector.c = 1;
	params->camera.pos.x = 0;
	params->camera.pos.y = 0;
	params->camera.pos.z = -10;
	params->camera.fov = 60;

	params->light = NULL;
	params->plane = NULL;
	params->cylinder = NULL;
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_params	params;

	TEMP_simulation(&params); // replace with parser
	if (initialise_map(&params) == NULL)
		return (1);
	params.mlx = mlx_init();
	params.window = mlx_new_window(params.mlx, WIDTH, HEIGHT,
			"Made by math haters");
	render(&params);
	return (0);
}
