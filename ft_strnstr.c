/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 18:41:50 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/16 14:33:19 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief locate a substring in a string
 * 
 * @param big 
 * @param little 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (big[i] && i + little_len <= len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (j == little_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
