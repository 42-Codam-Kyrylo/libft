#include "libft.h"
#include <criterion/criterion.h>

static void	assert_and_free(char *got, const char *expected)
{
	cr_assert_not_null(got, "ft_strtrim returned NULL unexpectedly");
	cr_assert_str_eq(got, expected, "Expected \"%s\", got \"%s\"", expected,
		got);
	free(got);
}

Test(ft_strtrim, basic_trim)
{
	char	*res;

	res = ft_strtrim("  hello  ", " ");
	assert_and_free(res, "hello");
}

Test(ft_strtrim, trim_tabs_and_spaces)
{
	char	*res;

	res = ft_strtrim("\t\n 42 school \n\t ", " \n\t");
	assert_and_free(res, "42 school");
}

Test(ft_strtrim, no_trim_needed)
{
	char	*res;

	res = ft_strtrim("libft", " ");
	assert_and_free(res, "libft");
}

Test(ft_strtrim, remove_all)
{
	char	*res;

	res = ft_strtrim("xxxx", "x");
	assert_and_free(res, "");
}

Test(ft_strtrim, empty_string)
{
	char	*res;

	res = ft_strtrim("", " ");
	assert_and_free(res, "");
}

Test(ft_strtrim, empty_set)
{
	char	*res;

	res = ft_strtrim("abc", "");
	assert_and_free(res, "abc");
}

Test(ft_strtrim, null_s1)
{
	char *res;

	res = ft_strtrim(NULL, " ");
	cr_assert_null(res, "Expected NULL when s1 is NULL");
}