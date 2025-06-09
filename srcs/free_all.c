/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:21:26 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/09 10:31:17 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_light(t_params *params)
{
	int	i;

	i = -1;
	if (!params->light)
		return ;
	while (params->light[++i])
		free(params->light[i]);
	free(params->light);
}

void	free_plane(t_params *params)
{
	int	i;

	i = -1;
	if (!params->plane)
		return ;
	while (params->plane[++i])
		free(params->plane[i]);
	free(params->plane);
}

void	free_cylinder(t_params *params)
{
	int	i;

	i = -1;
	if (!params->cylinder)
		return ;
	while (params->cylinder[++i])
		free(params->cylinder[i]);
	free(params->cylinder);
}

void	free_sphere(t_params *params)
{
	int	i;

	i = -1;
	if (!params->sphere)
		return ;
	while (params->sphere[++i])
		free(params->sphere[i]);
	free(params->sphere);
}

void	free_all(t_params *params)
{
	free_light(params);
	free_plane(params);
	free_cylinder(params);
	free_sphere(params);
}
