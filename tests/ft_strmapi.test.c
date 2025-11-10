#include "libft.h"
#include <criterion/criterion.h>

static char test_upper(unsigned int i, char c)
{
	if (i % 2 == 1 && c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}

static char test_shift(unsigned int i, char c)
{
	if (i)
	{
	}
	return c + 1;
}

Test(ft_strmapi_test, odd_to_upper)
{
	char *s = "hello";
	char *want = "hElLo";
	char *got = ft_strmapi(s, test_upper);

	cr_assert_str_eq(got, want, "got: %s, want: %s", got, want);
	free(got);
}

Test(ft_strmapi_test, shift_all_chars)
{
	char *s = "abc";
	char *want = "bcd";
	char *got = ft_strmapi(s, test_shift);

	cr_assert_str_eq(got, want, "got: %s, want: %s", got, want);
	free(got);
}

Test(ft_strmapi_test, empty_string)
{
	char *s = "";
	char *want = "";
	char *got = ft_strmapi(s, test_upper);

	cr_assert_str_eq(got, want, "got: %s, want: %s", got, want);
	free(got);
}

Test(ft_strmapi_test, null_string)
{
	ft_strmapi(NULL, test_upper);
	cr_assert(1, "Should not crash with NULL string");
}

Test(ft_strmapi_test, null_function)
{
	char	s[] = "test";
	char	want[] = "test";

	char *got = ft_strmapi(s, NULL);
	cr_assert_str_eq(got, want, "String should remain unchanged with NULL function");
}