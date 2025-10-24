/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/11 16:58:48 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/20 17:59:49 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief returns a pointer to the last
 * occurrence of the character c in the string s or NULL
 *
 * @param s
 * @param c
 * @return char*
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*matched;

	matched = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			matched = ((char *)(s + i));
		}
		i++;
	}
	if (matched)
		return (matched);
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
