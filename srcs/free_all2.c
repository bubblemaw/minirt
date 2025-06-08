/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 00:03:01 by hoannguy          #+#    #+#             */
/*   Updated: 2025/06/09 00:27:17 by hoannguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_map(t_params *params)
{
	int	i;

	if (!params->map)
		return;
	i = 0;
	while (params->map[i] != NULL)
	{
		free(params->map[i]);
		i++;
	}
	free(params->map);
}
