/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:39:14 by masase            #+#    #+#             */
/*   Updated: 2025/06/23 12:08:00 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	TEMP_simulation(t_params *params)
{
	// SPHERE
	t_sphere	*sphere1;
	t_sphere	*sphere2;
	t_sphere	*sphere3;
	t_sphere	*sphere4;

	sphere1 = malloc(sizeof(t_sphere));
	sphere1->pos.x = 0;
	sphere1->pos.y = 0;
	sphere1->pos.z = 0;
	sphere1->d = 70;
	sphere1->color.r = 255;
	sphere1->color.g = 255;
	sphere1->color.b = 255;

	sphere2 = malloc(sizeof(t_sphere));
	sphere2->pos.x = 0;
	sphere2->pos.y = 0;
	sphere2->pos.z = 0;
	sphere2->d = 5;
	sphere2->color.r = 255;
	sphere2->color.g = 255;
	sphere2->color.b = 255;

	sphere3 = malloc(sizeof(t_sphere));
	sphere3->pos.x = 6;
	sphere3->pos.y = -2;
	sphere3->pos.z = -5;
	sphere3->d = 5;
	sphere3->color.r = 255;
	sphere3->color.g = 255;
	sphere3->color.b = 255;
	
	sphere4 = malloc(sizeof(t_sphere));
	sphere4->pos.x = -27;
	sphere4->pos.y = -15;
	sphere4->pos.z = -30;
	sphere4->d = 5;
	sphere4->color.r = 255;
	sphere4->color.g = 255;
	sphere4->color.b = 255;

	params->sphere = malloc(sizeof(t_sphere *) * 5);
	params->sphere[0] = sphere1;
	params->sphere[1] = sphere2;
	params->sphere[2] = sphere3;
	params->sphere[3] = sphere4;
	params->sphere[4] = NULL;

	// PLANE
	t_plane	*plane1;
	t_plane *plane2;

	plane1 = malloc(sizeof(t_plane));
	plane1->vector.a = 0.5;
	plane1->vector.b = 0;
	plane1->vector.c = -0.5;
	plane1->pos.x = 0;
	plane1->pos.y = -25;
	plane1->pos.z = 35;
	plane1->color.r = 255;
	plane1->color.g = 255;
	plane1->color.b = 255;

	plane2 = malloc(sizeof(t_plane));
	plane2->vector.a = 0;
	plane2->vector.b = -1;
	plane2->vector.c = 0;
	plane2->pos.x = 0;
	plane2->pos.y = -20;
	plane2->pos.z = 45;
	plane2->color.r = 255;
	plane2->color.g = 255;
	plane2->color.b = 255;

	params->plane = malloc(sizeof(t_plane *) * 3);
	params->plane[0] = plane1;
	params->plane[1] = plane2;
	params->plane[2] = NULL;

	// CAMERA
	params->camera.vector.a = 0;
	params->camera.vector.b = 0;
	params->camera.vector.c = 1;
	params->camera.pos.x = 0;
	params->camera.pos.y = 0;
	params->camera.pos.z = -19;
	params->camera.fov = 70;

	// AMBIENT
	params->ambient.ratio = 0.6;
	params->ambient.color.r = 0;
	params->ambient.color.g = 0;
	params->ambient.color.b = 0;


	// LIGHT
	t_light	*light1;
	t_light	*light2;
	t_light	*light3;
	t_light	*light4;
	t_light	*light5;

	light1 = malloc(sizeof(t_light));
	light1->pos.x = 0;
	light1->pos.y = 0;
	light1->pos.z = -5;
	light1->ratio = 1;
	light1->color.r = 0;
	light1->color.g = 255;
	light1->color.b = 0;

	light2 = malloc(sizeof(t_light));
	light2->pos.x = 0;
	light2->pos.y = -7;
	light2->pos.z = -5;
	light2->ratio = 1;
	light2->color.r = 255;
	light2->color.g = 0;
	light2->color.b = 0;

	light3 = malloc(sizeof(t_light));
	light3->pos.x = 20.0;
	light3->pos.y = 40.0;
	light3->pos.z = -40.0;
	light3->ratio = 1;
	light3->color.r = 0;
	light3->color.g = 0;
	light3->color.b = 255;

	light4 = malloc(sizeof(t_light));
	light4->pos.x = -36.0;
	light4->pos.y = -15.0;
	light4->pos.z = -30;
	light4->ratio = 1;
	light4->color.r = 255;
	light4->color.g = 0;
	light4->color.b = 255;

	light5 = malloc(sizeof(t_light));
	light5->pos.x = 0;
	light5->pos.y = 0;
	light5->pos.z = 0;
	light5->ratio = 1;
	light5->color.r = 0;
	light5->color.g = 0;
	light5->color.b = 255;

	params->light = malloc(sizeof(t_light *) * 6);
	params->light[0] = light1;
	params->light[1] = light2;
	params->light[2] = light3;
	params->light[3] = light4;
	params->light[4] = light5;
	params->light[5] = NULL;

	// OTHER
	params->cylinder = NULL;
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
    t_params params;
    // ft_memset(&params, 0, sizeof(t_params));

    // printf("let's print my objects\n");
    // print_ambiance_as_array(&params.ambient);
    // print_camera_as_array(&params.camera);
    // print_cylinder_as_array(params.cylinder[0]);
    // print_plane_as_array(params.plane[0]);
    // print_point_as_array(params.light[0]);
    // print_point_as_array(params.light[1]);
    // print_sphere_as_array(params.sphere[0]);

	TEMP_simulation(&params); // replace with parser
    // if (parsing(av[1], &params) == FALSE)
	// 	return (FALSE);
	// print_sphere_as_array(params.sphere[0]);
	// print_sphere_as_array(params.sphere[1]);
	// print_sphere_as_array(params.sphere[2]);	
	params.mlx = mlx_init();
	params.window = mlx_new_window(params.mlx, WIDTH, HEIGHT,
			"Made by math haters");
	render(&params);
	return (0);
}
