/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/08 13:53:30 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 14:09:23 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	is_ascii;

	is_ascii = c >= 0 && c <= 127;
	if (is_ascii)
	{
		return (1);
	}
	return (0);
}
