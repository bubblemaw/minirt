/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:39:14 by masase            #+#    #+#             */
/*   Updated: 2025/06/11 19:42:21 by maw              ###   ########.fr       */
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
    print_ambiance_as_array(&params.ambient);
    print_camera_as_array(&params.camera);
    return(0);
}