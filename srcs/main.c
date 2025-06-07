/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:39:14 by masase            #+#    #+#             */
/*   Updated: 2025/06/07 21:37:31 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int main(int ac,  char **av)
{
    (void)ac;
    (void)av;
    t_params    *params;

    params = malloc(sizeof(params));
    if (!params)
        return (1);
    if (!run(params))
        return (free(params), 1); // free properly later
    return(0);
}