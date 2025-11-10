#include "libft.h"
#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdlib.h>

static bool	del_called = false;
static void	test_del(void *content)
{
	del_called = true;
	free(content);
}

Test(ft_lstdelone_test, delete_single_node)
{
	t_list	*node;

	del_called = false;
	node = ft_lstnew(malloc(10));
	ft_lstdelone(node, test_del);
	cr_assert(del_called, "The del function should be called");
}

Test(ft_lstdelone_test, delete_node_with_next)
{
	t_list	*node1;
	t_list	*node2;

	del_called = false;
	node1 = ft_lstnew(malloc(10));
	node2 = ft_lstnew(malloc(10));
	node1->next = node2;
	ft_lstdelone(node1, test_del);
	cr_assert(del_called, "The del function should be called");
	cr_assert_not_null(node2, "Next node must not be freed by ft_lstdelone");
	free(node2->content);
	free(node2);
}

Test(ft_lstdelone_test, null_node)
{
	del_called = false;
	ft_lstdelone(NULL, test_del);
	cr_assert_not(del_called, "del should not be called for NULL node");
}

Test(ft_lstdelone_test, null_del_function)
{
	t_list	*node;

	node = ft_lstnew(malloc(10));
	ft_lstdelone(node, NULL);
}
