/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 15:23:20 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 14:09:32 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s_for_search;
	unsigned char		c_to_search;

	s_for_search = (const unsigned char *)s;
	c_to_search = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_for_search[i] == c_to_search)
		{
			return ((void *)s_for_search + i);
		}
		i++;
	}
	return (NULL);
}
