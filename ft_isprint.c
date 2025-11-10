/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/08 14:03:47 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 14:09:30 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	int	is_printable;

	is_printable = c >= 32 && c <= 126;
	if (is_printable)
	{
		return (1);
	}
	return (0);
}
