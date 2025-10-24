/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/11 17:15:52 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/16 15:12:56 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief compares first n charachers 
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((str1[i] && str2[i]) && i < n - 1)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - s2[i]);
}
