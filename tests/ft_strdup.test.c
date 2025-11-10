#include "libft.h"
#include <criterion/criterion.h>

Test(ft_strdup_test, success_duplicate)
{
	char str[] = "Hello world!";
	char *strDup = ft_strdup(str);
	cr_assert_str_eq(strDup, str, "got: %s, want: %s", strDup, str);
	free(strDup);
}

Test(ft_strdup_test, long_string)
{
	char str[] = "Hello world! iii am looooooooooooooooooongggg enooooooughhhh striiiing. reeeeeeeelllyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong";
	char *strDup = ft_strdup(str);
	cr_assert_str_eq(strDup, str, "got: %s, want: %s", strDup, str);
	free(strDup);
}

Test(ft_strdup_test, null_input)
{
	char *strDup = ft_strdup(NULL);
	cr_assert_null(strDup, "want null for NULL input, got %s", strDup);
	free(strDup);
}
