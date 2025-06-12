/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:50:48 by masase            #+#    #+#             */
/*   Updated: 2025/06/12 14:54:42 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
	{
		free (ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free (ptr);
		return (NULL);
	}
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	new_ptr = ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

void *alloc_tab(t_params *params, e_tab_type type)
{
	void **tab;
	int	*current_size;
	size_t element_size;

	if (type == LIGHT)
	{
		tab = (void **)&params->light;
		current_size = &params->quantity.light;
		element_size = sizeof(t_light *); 
	}
	else if (type == PLANE)
	{
		tab = (void **)&params->plane;
		current_size = &params->quantity.plane;
		element_size = sizeof(t_plane *); 
	}
	else if (type == CYLINDER)
	{
		tab = (void **)&params->cylinder;
		current_size = &params->quantity.cylinder;
		element_size = sizeof(t_cylinder *); 
	}
	else if (type == SPHERE)
	{
		tab = (void **)&params->sphere;
		current_size = &params->quantity.sphere;
		element_size = sizeof(t_sphere *); 
	}
	*tab = ft_realloc (params->light,
	element_size * (*current_size),
	element_size * ((*current_size) + 2));
	if (*tab == NULL)
		return (NULL);
	(*current_size)++;
	return (*tab);	
}
