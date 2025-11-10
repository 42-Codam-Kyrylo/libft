/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 11:43:51 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/16 14:34:35 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*handle_start_after_src(char *substr)
{
	substr = (char *)malloc(sizeof(char));
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

/**
 * @brief returns a
substring from the string ’s’.
The substring starts at index ’start’ and has a
maximum length of ’len’.
 *
 * @param s
 * @param start
 * @param len
 * @return char*
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	src_len;

	substr = NULL;
	if (s == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (handle_start_after_src(substr));
	if (src_len - start < len)
		len = src_len - start;
	substr = (char *)malloc(len + 1 * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
