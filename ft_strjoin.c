/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 14:20:33 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/16 13:23:33 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/**
 * @brief returns a new string s1 + s2
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*result;

	str1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	result = (char *)malloc((str1_len + str2_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, (str1_len + str2_len + 1));
	ft_strlcat(result, s2, (str1_len + str2_len + 1));
	return (result);
}
