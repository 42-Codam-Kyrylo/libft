#include "libft.h"
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>

static int del_count = 0;
static void test_del(void *content)
{
	del_count++;
	free(content);
}

static t_list *create_node(const char *str)
{
	return ft_lstnew(strdup(str));
}

Test(ft_lstclear_test, clear_multiple_nodes)
{
	del_count = 0;

	t_list *n1 = create_node("node 1");
	t_list *n2 = create_node("node 2");
	t_list *n3 = create_node("node 3");
	n1->next = n2;
	n2->next = n3;

	t_list *list = n1;

	ft_lstclear(&list, test_del);

	cr_assert_eq(del_count, 3, "del should be called for each node");
	cr_assert_null(list, "list pointer should be NULL after ft_lstclear");
}

Test(ft_lstclear_test, clear_single_node)
{
	del_count = 0;
	t_list *node = create_node("single node");

	ft_lstclear(&node, test_del);

	cr_assert_eq(del_count, 1, "del should be called once for single node");
	cr_assert_null(node, "node pointer should be NULL after ft_lstclear");
}

Test(ft_lstclear_test, clear_null_list)
{
	del_count = 0;
	t_list *list = NULL;

	ft_lstclear(&list, test_del);

	cr_assert_eq(del_count, 0, "del should not be called for NULL list");
	cr_assert_null(list, "list pointer should still be NULL");
}
