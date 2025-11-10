#include "libft.h"
#include <criterion/criterion.h>

Test(ft_itoa_test, basic_itoa)
{
	char *want = "1008";
	char *got = ft_itoa(1008);

	cr_assert_str_eq(got, want, "got: %s, want: %s", got, want);
	free(got);
}
Test(ft_itoa_test, negative)
{
	char *want = "-1008";
	char *got = ft_itoa(-1008);

	cr_assert_str_eq(got, want, "got: %s, want: %s", got, want);
	free(got);
}
Test(ft_itoa_test, positive_with_plus)
{
	char *want = "1008";
	char *got = ft_itoa(+1008);

	cr_assert_str_eq(got, want, "got: %s, want: %s", got, want);
	free(got);
}
Test(ft_itoa_test, want_zero)
{
	char *want = "0";
	char *got = ft_itoa(0);

	cr_assert_str_eq(got, want, "got: %s, want: %s", got, want);
	free(got);
}
Test(ft_itoa_test, min_int)
{
	char *want = "-2147483648";
	char *got = ft_itoa(-2147483648);

	cr_assert_str_eq(got, want, "got: %s, want: %s", got, want);
	free(got);
}
