/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:39:14 by masase            #+#    #+#             */
/*   Updated: 2025/06/09 15:44:36 by masase           ###   ########.fr       */
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
    printf("%f  ,%d-%d-%d\n", scene.amb.ratio, scene.amb.R,scene.amb.G,scene.amb.B);  
    return(0);
}