#include "libft.h"
#include <stdlib.h>
#include <criterion/criterion.h>

static void free_list(t_list *my_list)
{
	t_list *tmp;
	while (my_list)
	{
		tmp = my_list->next;
		free(my_list);
		my_list = tmp;
	}
}

Test(ft_lstadd_front_test, successfully_add)
{
	t_list *my_list = ft_lstnew("node 1");
	my_list->next = ft_lstnew("node 2");
	ft_lstadd_front(&my_list, ft_lstnew("new node to front"));

	cr_assert_str_eq((char *)my_list->content, "new node to front");
	cr_assert_str_eq((char *)my_list->next->content, "node 1");
	cr_assert_null(my_list->next->next->next);

	free_list(my_list);
}

Test(ft_lstadd_front_test, add_to_empty_list)
{
	t_list *my_list = NULL;

	ft_lstadd_front(&my_list, ft_lstnew("first node"));

	cr_assert_not_null(my_list);
	cr_assert_str_eq((char *)my_list->content, "first node");
	cr_assert_null(my_list->next);

	free_list(my_list);
}
