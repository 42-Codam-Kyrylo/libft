/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 14:17:39 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 14:09:26 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d", ft_isdigit('1'));
// 	printf("%d", ft_isdigit('8'));
// 	printf("%d", ft_isdigit('-'));
// 	printf("%d", ft_isdigit('g'));
// }
