/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 13:51:45 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 14:09:20 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d", ft_isalpha('A'));
// 	printf("%d", ft_isalpha('z'));
// 	printf("%d", ft_isalpha('-'));
// 	printf("%d", ft_isalpha('9'));
// }