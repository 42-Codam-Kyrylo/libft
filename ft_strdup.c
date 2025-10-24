/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 21:06:49 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/24 15:29:14 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief returns a pointer to a new string which is a duplicate of the string s
 *
 * @param s
 * @return char*
 */
char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	duplicate_len;

	if (!s)
		return (NULL);
	duplicate_len = ft_strlen(s) + 1;
	duplicate = (char *)malloc(duplicate_len * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	ft_strlcpy(duplicate, s, duplicate_len);
	return (duplicate);
}
