/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 13:31:35 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/15 14:09:41 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if (!dest && !src)
		return (NULL);
	i = 0;
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (dest > src)
	{
		while (n--)
			p_dest[n] = p_src[n];
	}
	else
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}

// Learningisfun
// memmove - LearningLearningis
// memcpy - LearningLearningLe
