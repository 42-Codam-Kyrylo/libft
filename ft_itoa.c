/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/20 14:51:47 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/21 19:00:07 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

static int	calculate_amount_of_numbers(int *n, bool *is_negative)
{
	int	length_of_string;
	int	n_copy;

	*is_negative = false;
	length_of_string = 0;
	if (*n < 0)
	{
		*is_negative = true;
		*n *= -1;
		length_of_string++;
	}
	n_copy = *n;
	if (n_copy == 0)
	{
		length_of_string = 1;
	}
	while (n_copy > 0)
	{
		length_of_string++;
		n_copy /= 10;
	}
	return (length_of_string);
}

static char	*handle_min_int(void)
{
	char	*result;

	result = (char *)malloc(12 * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, "-2147483648", 12);
	return (result);
}

/**
 * @brief returns a string representing the integer received as an
argument
 *
 * @param n
 * @return char*
 * @warning free than by your self
 */
char	*ft_itoa(int n)
{
	bool	is_negative;
	int		length_of_string;
	char	*result;
	int		i;

	if (n == INT_MIN)
		return (handle_min_int());
	length_of_string = calculate_amount_of_numbers(&n, &is_negative);
	result = (char *)ft_calloc((length_of_string + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length_of_string)
	{
		if (is_negative && n < 10)
		{
			result[length_of_string - 1 - i] = (n % 10) + '0';
			result[length_of_string - 2 - i] = '-';
			break ;
		}
		result[length_of_string - 1 - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	return (result);
}
