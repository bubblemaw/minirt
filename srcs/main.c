/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:39:14 by masase            #+#    #+#             */
/*   Updated: 2025/06/12 14:59:01 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int main(int ac,  char **av)
{
    (void)ac;
    (void)av;
    t_params params;
    ft_memset(&params, 0, sizeof(t_params));

    // printf("%f\n", ft_atof(av[1]));
    // printf("atof: %f\n", atof(av[1]));
    parsing(av[1], &params);
    printf("let's print my objects\n");
    print_ambiance_as_array(&params.ambient);
    print_camera_as_array(&params.camera);
    print_cylinder_as_array(params.cylinder[0]);
    print_plane_as_array(params.plane[0]);
    print_point_as_array(params.light[0]);
    print_sphere_as_array(params.sphere[0]);
    return(0);
}