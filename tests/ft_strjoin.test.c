#include "libft.h"
#include <criterion/criterion.h>

Test(ft_strjoin_test, success_joining)
{
	char str1[] = "hello ";
	char str2[] = "world!";
	char expected[] = "hello world!";
	char *result = ft_strjoin(str1, str2);
	cr_assert_str_eq(result, expected);
	free(result);
}