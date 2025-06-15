/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:39:14 by masase            #+#    #+#             */
/*   Updated: 2025/06/15 12:30:59 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	TEMP_simulation(t_params *params)
{
	t_sphere	*sphere1;
	t_sphere	*sphere2;
	t_sphere	*sphere3;

	sphere1 = malloc(sizeof(t_sphere));
	sphere1->pos.x = 0;
	sphere1->pos.y = 0;
	sphere1->pos.z = 15;
	sphere1->d = 3;
	sphere1->color.r = 255;
	sphere1->color.g = 0;
	sphere1->color.b = 0;

	sphere2 = malloc(sizeof(t_sphere));
	sphere2->pos.x = 3;
	sphere2->pos.y = 1;
	sphere2->pos.z = 15;
	sphere2->d = 5;
	sphere2->color.r = 0;
	sphere2->color.g = 255;
	sphere2->color.b = 0;

	sphere3 = malloc(sizeof(t_sphere));
	sphere3->pos.x = -5;
	sphere3->pos.y = -4;
	sphere3->pos.z = 20;
	sphere3->d = 7;
	sphere3->color.r = 0;
	sphere3->color.g = 0;
	sphere3->color.b = 255;

	params->sphere = malloc(sizeof(t_sphere *) * 4);
	params->sphere[0] = sphere1;
	params->sphere[1] = sphere2;
	params->sphere[2] = sphere3;
	params->sphere[3] = NULL;

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
    t_params params;
    ft_memset(&params, 0, sizeof(t_params));

    // printf("let's print my objects\n");
    // print_ambiance_as_array(&params.ambient);
    // print_camera_as_array(&params.camera);
    // print_cylinder_as_array(params.cylinder[0]);
    // print_plane_as_array(params.plane[0]);
    // print_point_as_array(params.light[0]);
    // print_point_as_array(params.light[1]);
    // print_sphere_as_array(params.sphere[0]);

	// TEMP_simulation(&params); // replace with parser
    if (parsing(av[1], &params) == FALSE)
		return (FALSE);
	print_sphere_as_array(params.sphere[0]);
	// print_sphere_as_array(params.sphere[1]);
	// print_sphere_as_array(params.sphere[2]);	
	params.mlx = mlx_init();
	params.window = mlx_new_window(params.mlx, WIDTH, HEIGHT,
			"Made by math haters");
	render(&params);
	return (0);
}
