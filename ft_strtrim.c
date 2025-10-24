/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/16 12:37:51 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/16 16:00:43 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.
 *
 * @param s1
 * @param set
 * @return char*
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_start;
	size_t	str_end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	str_start = 0;
	while (s1[str_start] && is_in_set(s1[str_start], set))
		str_start++;
	str_end = ft_strlen(s1);
	while (str_end > str_start && is_in_set(s1[str_end - 1], set))
		str_end--;
	return (ft_substr(s1, str_start, str_end - str_start));
}
