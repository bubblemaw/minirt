/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:39:14 by masase            #+#    #+#             */
/*   Updated: 2025/06/10 11:38:19 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int main(int ac,  char **av)
{
    (void)ac;
    (void)av;
    t_scene scene;
    ft_memset(&scene, 0, sizeof(t_scene));

    // printf("%f\n", ft_atof(av[1]));
    // printf("atof: %f\n", atof(av[1]));
    parsing(av[1], &scene);
    print_ambiance_as_array(&scene.amb);
    print_camera_as_array(&scene.camera);
    return(0);
}