/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/10 12:45:37 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 19:49:08 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief copys src to dest, adds `\0`, if size enough
 *
 * @param dst
 * @param src
 * @param size of dest
 * @return size_t
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(src);
	if (size == 0)
	{
		return (str_len);
	}
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (str_len);
}
