/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:33:45 by maw               #+#    #+#             */
/*   Updated: 2024/10/11 15:11:01 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;
	char	cc;

	cc = (char) c;
	last = NULL;
	while (*str)
	{
		if (*str == cc)
			last = (char *) str;
		str++;
	}
	if (cc == '\0')
		return ((char *) str);
	return (last);
}

/*
Returns a pointer to the first occurrence
of character in the C string str from the right
The terminating null-character is considered part of
the C string.
Therefore, it can also be located in order to retrieve a
pointer to the end of a string.
int main (void)
{
	char str[] = "je ne suis pas dans les classements";
	printf("%d", ft_strrchr(str, 's'));
	return (0);
}
*/