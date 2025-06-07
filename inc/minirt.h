/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:05:52 by masase            #+#    #+#             */
/*   Updated: 2025/06/07 21:42:05 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h" 

#define HEIGHT 720
#define WIDTH 1080

typedef struct	s_vector
{
	float	a;
	float	b;
	float	c;
}	t_vector;

typedef struct	s_params
{
	t_vector	vector;
}	t_params;

// PARSING -------------------------------

// RAYON ---------------------------------
int	run(t_params *params);

// LIGHT ---------------------------------

// SHADOW --------------------------------

#endif 
