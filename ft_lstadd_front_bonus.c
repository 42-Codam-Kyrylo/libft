/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/22 13:29:31 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/24 15:45:35 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 *
 * @param lst
 * @param new
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst);
	*lst = new;
}
// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = (*lst)->next;
// 	(*lst)->next = new;
// }
