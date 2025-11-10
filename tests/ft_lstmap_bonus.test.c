#include "libft.h"
#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>

static void *increment_copy(void *content)
{
	int *new_val = malloc(sizeof(int));
	*new_val = (*(int *)content) + 1;
	return new_val;
}

static void *to_uppercase_copy(void *content)
{
	char *str = strdup((char *)content);
	for (int i = 0; str[i]; i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return str;
}

Test(ft_lstmap_test, maps_integers_correctly)
{
	int a = 1, b = 2, c = 3;
	t_list *n1 = ft_lstnew(&a);
	t_list *n2 = ft_lstnew(&b);
	t_list *n3 = ft_lstnew(&c);
	n1->next = n2;
	n2->next = n3;

	t_list *result = ft_lstmap(n1, increment_copy, free);

	cr_assert_not_null(result);
	cr_assert_eq(*(int *)result->content, 2);
	cr_assert_eq(*(int *)result->next->content, 3);
	cr_assert_eq(*(int *)result->next->next->content, 4);

	ft_lstclear(&result, free);
	free(n1);
	free(n2);
	free(n3);
}

Test(ft_lstmap_test, maps_strings_correctly)
{
	t_list *n1 = ft_lstnew(strdup("hello"));
	t_list *n2 = ft_lstnew(strdup("world"));
	n1->next = n2;

	t_list *result = ft_lstmap(n1, to_uppercase_copy, free);

	cr_assert_str_eq((char *)result->content, "HELLO");
	cr_assert_str_eq((char *)result->next->content, "WORLD");

	ft_lstclear(&result, free);
	ft_lstclear(&n1, free);
}

Test(ft_lstmap_test, handles_null_list)
{
	t_list *result = ft_lstmap(NULL, increment_copy, free);
	cr_assert_null(result);
}

Test(ft_lstmap_test, handles_null_function)
{
	int a = 5;
	t_list *n1 = ft_lstnew(&a);
	t_list *result = ft_lstmap(n1, NULL, free);
	cr_assert_null(result);
	free(n1);
}
