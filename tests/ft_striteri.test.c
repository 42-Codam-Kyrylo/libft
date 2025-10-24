#include "libft.h"
#include <criterion/criterion.h>
#include <string.h>

static void	to_upper_odd(unsigned int i, char *c)
{
	if (i % 2 == 1 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

static void	shift_by_one(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1;
}

static void	add_index(unsigned int i, char *c)
{
	*c = *c + i;
}

static void	to_upper_all(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

Test(ft_striteri_test, odd_positions_to_upper)
{
	char	s[] = "hello world";
	char	want[] = "hElLo wOrLd";

	ft_striteri(s, to_upper_odd);
	cr_assert_str_eq(s, want, "got: %s, want: %s", s, want);
}

Test(ft_striteri_test, shift_all_chars)
{
	char	s[] = "abc";
	char	want[] = "bcd";

	ft_striteri(s, shift_by_one);
	cr_assert_str_eq(s, want, "got: %s, want: %s", s, want);
}

Test(ft_striteri_test, add_index_to_each)
{
	char	s[] = "aaaa";
	char	want[] = "abcd";

	ft_striteri(s, add_index);
	cr_assert_str_eq(s, want, "got: %s, want: %s", s, want);
}

Test(ft_striteri_test, uppercase_all)
{
	char	s[] = "test string";
	char	want[] = "TEST STRING";

	ft_striteri(s, to_upper_all);
	cr_assert_str_eq(s, want, "got: %s, want: %s", s, want);
}

Test(ft_striteri_test, empty_string)
{
	char	s[] = "";
	char	want[] = "";

	ft_striteri(s, to_upper_odd);
	cr_assert_str_eq(s, want, "got: %s, want: %s", s, want);
}

Test(ft_striteri_test, single_char)
{
	char	s[] = "a";
	char	want[] = "A";

	ft_striteri(s, to_upper_all);
	cr_assert_str_eq(s, want, "got: %s, want: %s", s, want);
}

Test(ft_striteri_test, null_string)
{
	ft_striteri(NULL, to_upper_all);
	cr_assert(1, "Should not crash with NULL string");
}

Test(ft_striteri_test, null_function)
{
	char	s[] = "test";
	char	want[] = "test";

	ft_striteri(s, NULL);
	cr_assert_str_eq(s, want, "String should remain unchanged with NULL function");
}