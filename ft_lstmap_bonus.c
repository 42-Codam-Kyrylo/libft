/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvolynsk <kvolynsk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/22 15:50:26 by kvolynsk      #+#    #+#                 */
/*   Updated: 2025/10/23 15:08:32 by kvolynsk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates through the list ’lst’, applies the
function ’f’ to each node’s content, and creates
a new list resulting of the successive applications
of the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
 *
 * @param lst
 * @param f
 * @param del
 * @return t_list*
 */

static void	initialize_list(t_list **new_list, t_list *new_node,
		t_list **current, t_list **lst)
{
	*new_list = new_node;
	*current = new_node;
	*lst = (*lst)->next;
}

static void	move_though_list(t_list *new_node, t_list **current, t_list **lst)
{
	*current = new_node;
	*lst = (*lst)->next;
}

static t_list	*handle_failed_new_node(void (*del)(void *), void **new_content,
		t_list **new_list)
{
	if (del)
		del(*new_content);
	ft_lstclear(new_list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_node;
	void	*new_content;

	if (!f)
		return (NULL);
	new_list = NULL;
	current = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
			return (handle_failed_new_node(del, &new_content, &new_list));
		if (new_list == NULL)
		{
			initialize_list(&new_list, new_node, &current, &lst);
			continue ;
		}
		current->next = new_node;
		move_though_list(new_node, &current, &lst);
	}
	return (new_list);
}
