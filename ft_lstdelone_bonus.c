/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/22 15:05:55 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/22 15:16:16 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Takes a node as parameter and frees its content
using the function ’del’. Free the node itself
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete
the content
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
	{
		return ;
	}
	del(lst->content);
	free(lst);
}
