/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/10 14:19:00 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 19:40:58 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief concatenete src to destination and add a '\0' to add if enough size
 *
 * @param dst
 * @param src
 * @param size of destination
 * @return size_t
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size == 0)
		return (src_len);
	if (dst_len >= size)
	{
		return (size + src_len);
	}
	i = 0;
	while (src[i] && i < size - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
