#include "libft.h"
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static void increment_int(void *content)
{
	int *p = (int *)content;
	(*p)++;
}

static void to_uppercase(void *content)
{
	char *str = (char *)content;
	for (int i = 0; str[i]; i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
}

Test(ft_lstiter_test, iterates_over_ints)
{
	int a = 1, b = 2, c = 3;

	t_list *n1 = ft_lstnew(&a);
	t_list *n2 = ft_lstnew(&b);
	t_list *n3 = ft_lstnew(&c);
	n1->next = n2;
	n2->next = n3;

	ft_lstiter(n1, increment_int);

	cr_assert_eq(a, 2);
	cr_assert_eq(b, 3);
	cr_assert_eq(c, 4);

	free(n1);
	free(n2);
	free(n3);
}

Test(ft_lstiter_test, iterates_over_strings)
{
	char *s1 = strdup("hello");
	char *s2 = strdup("world");
	t_list *n1 = ft_lstnew(s1);
	t_list *n2 = ft_lstnew(s2);
	n1->next = n2;

	ft_lstiter(n1, to_uppercase);

	cr_assert_str_eq((char *)n1->content, "HELLO");
	cr_assert_str_eq((char *)n2->content, "WORLD");

	free(s1);
	free(s2);
	free(n1);
	free(n2);
}

Test(ft_lstiter_test, null_list)
{
	ft_lstiter(NULL, increment_int);
}

Test(ft_lstiter_test, null_function)
{
	int a = 5;
	t_list *n1 = ft_lstnew(&a);
	ft_lstiter(n1, NULL);
	cr_assert_eq(a, 5, "value should remain unchanged if f is NULL");
	free(n1);
}
