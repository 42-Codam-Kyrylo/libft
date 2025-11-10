/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/08 13:21:55 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 14:09:16 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	is_capital_alpha;
	int	is_lover_alpha;
	int	is_numeric;

	is_capital_alpha = c >= 'A' && c <= 'Z';
	is_lover_alpha = c >= 'a' && c <= 'z';
	is_numeric = c >= '0' && c <= '9';
	if (is_capital_alpha || is_lover_alpha || is_numeric)
	{
		return (1);
	}
	return (0);
}
