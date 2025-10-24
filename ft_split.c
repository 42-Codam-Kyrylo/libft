/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/16 16:23:15 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/20 17:52:17 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	calculate_str_to_create(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_split(char **split, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	feel_array(const char *s, char c, char **result,
		int number_of_strings_to_create)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] && j < number_of_strings_to_create)
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result[j] = ft_substr(s, start, i - start);
		if (!result[j])
		{
			free_split(result, j);
			return (0);
		}
		j++;
	}
	result[j] = NULL;
	return (1);
}

/**
 * @brief returns an arr of strings btained by splitting @p `s` using @p `c`
 *
 * @param[in] s string to be split
 * @param[in] c delimiter
 * @return char** end with NULL pointer or NULL
 *
 * @warning Caller owns free().
 */
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		number_of_strings_to_create;

	if (!s)
		return (NULL);
	number_of_strings_to_create = calculate_str_to_create(s, c);
	result = malloc((number_of_strings_to_create + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!feel_array(s, c, result, number_of_strings_to_create))
		return (NULL);
	return (result);
}
