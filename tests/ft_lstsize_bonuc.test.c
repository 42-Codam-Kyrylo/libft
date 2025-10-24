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

Test(ft_lstsize_test, size_of_list)
{
	t_list *my_list = ft_lstnew("node 1");
	my_list->next = ft_lstnew("node 2");
	ft_lstadd_front(&my_list, ft_lstnew("new node to front"));

	int sizeOfList = ft_lstsize(my_list);
	cr_assert_eq(sizeOfList, 3, "expected 3 nodes in list, got %d", sizeOfList);

	free_list(my_list);
}

Test(ft_lstsize_test, size_of_empty)
{
	t_list *my_list = NULL;

	int sizeOfList = ft_lstsize(my_list);
	cr_assert_eq(sizeOfList, 0, "expected 0 nodes in list, got %d", sizeOfList);

	free_list(my_list);
}
