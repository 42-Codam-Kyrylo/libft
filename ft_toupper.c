/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/11 16:09:59 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/16 13:32:09 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	is_lower;

	is_lower = c >= 'a' && c <= 'z';
	if (!is_lower)
	{
		return (c);
	}
	return (c - 32);
}
