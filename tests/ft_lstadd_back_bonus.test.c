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

Test(ft_lstadd_back_test, success_add_last)
{
	t_list *my_list = ft_lstnew("node 1");
	my_list->next = ft_lstnew("node 2");
	ft_lstadd_front(&my_list, ft_lstnew("new node to front"));

	ft_lstadd_back(&my_list, ft_lstnew("last node"));
	t_list *lastList = ft_lstlast(my_list);

	cr_assert_str_eq((char *)lastList->content, "last node");
	cr_assert_null(lastList->next, "Next should be null for last node");

	free_list(my_list);
}
Test(ft_lstadd_back_test, add_last_to_null_list)
{
	t_list *my_list = NULL;

	ft_lstadd_back(&my_list, ft_lstnew("last node"));
	cr_assert_str_eq((char *)my_list->content, "last node");
	cr_assert_null(my_list->next, "Next should be null for last node");
}