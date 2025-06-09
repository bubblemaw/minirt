/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:11:43 by maw               #+#    #+#             */
/*   Updated: 2025/06/08 21:51:46 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	ft_atof(const char *str)
{
	int	i;
	int	signe;
	float	resultat;
	int point_flag;

	point_flag = 0;
	resultat = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
	{
		if (point_flag == 1)
			signe *= 10;
		if (str[i] == '.')
		{
			point_flag = 1;
			i++;
		}
		else
		{
			resultat *= 10;
			resultat = (str[i] - '0') + resultat;
			i++;
		}
	}
	resultat /= signe;
	return (resultat);
}
