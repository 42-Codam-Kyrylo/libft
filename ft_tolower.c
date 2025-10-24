/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/11 16:15:03 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 14:11:17 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	is_upper;

	is_upper = c >= 'A' && c <= 'Z';
	if (!is_upper)
	{
		return (c);
	}
	return (c + 32);
}
