#include "libft.h"
#include <criterion/criterion.h>

Test(ft_lstnew_test, successfully_create)
{
	char content[] = "Hello world!";
	t_list *newList = ft_lstnew(content);

	cr_assert_not_null(newList, "ft_lstnew returned NULL");
	cr_assert_eq(newList->content, content,
				 "expected content pointer %p, got %p", (void *)content, newList->content);
	cr_assert_null(newList->next, "expected next to be NULL");

	free(newList);
}
