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

Test(ft_lstlast_test, success_get_last)
{
	t_list *my_list = ft_lstnew("node 1");
	my_list->next = ft_lstnew("node 2");
	ft_lstadd_front(&my_list, ft_lstnew("new node to front"));

	t_list *lastList = ft_lstlast(my_list);

	cr_assert_str_eq((char *)lastList->content, "node 2");
	cr_assert_null(lastList->next, "Next should be null for last node");

	free_list(my_list);
}
Test(ft_lstlast_test, null_list)
{
	t_list *my_list = NULL;

	t_list *lastList = ft_lstlast(my_list);

	cr_assert_null(lastList, "ft_lstlast(NULL) should return NULL");
}