// #include "libft.h"
// #include <criterion/criterion.h>

// int calculate_str_to_create(const char *s, char c);

// Test(ft_spli_calculate_str_to_create, basic_split)
// {
// 	char *input = "Hello,world,how,are,you";
// 	int want = 5;
// 	char delim = ',';

// 	int got = calculate_str_to_create(input, delim);
// 	cr_assert_eq(got, want, "got %d, want %d", got, want);
// }
// Test(ft_spli_calculate_str_to_create, single_word)
// {
// 	char *input = "Hello";
// 	int want = 1;
// 	char delim = ',';

// 	int got = calculate_str_to_create(input, delim);
// 	cr_assert_eq(got, want, "got %d, want %d", got, want);
// }
// Test(ft_spli_calculate_str_to_create, only_delimiter)
// {
// 	char *input = ",,,,";
// 	int want = 0;
// 	char delim = ',';

// 	int got = calculate_str_to_create(input, delim);
// 	cr_assert_eq(got, want, "got %d, want %d", got, want);
// }
// Test(ft_spli_calculate_str_to_create, delimiters_at_edges)
// {
// 	char *input = ",a,b,";
// 	int want = 2;
// 	char delim = ',';

// 	int got = calculate_str_to_create(input, delim);
// 	cr_assert_eq(got, want, "got %d, want %d", got, want);
// }
// Test(ft_spli_calculate_str_to_create, empty_string)
// {
// 	char *input = "";
// 	int want = 0;
// 	char delim = ',';

// 	int got = calculate_str_to_create(input, delim);
// 	cr_assert_eq(got, want, "got %d, want %d", got, want);
// }
// Test(ft_spli_calculate_str_to_create, only_one_delim)
// {
// 	char *input = ",";
// 	int want = 0;
// 	char delim = ',';

// 	int got = calculate_str_to_create(input, delim);
// 	cr_assert_eq(got, want, "got %d, want %d", got, want);
// }
// Test(ft_spli_calculate_str_to_create, char_and_delim)
// {
// 	char *input = "a";
// 	int want = 1;
// 	char delim = ',';

// 	int got = calculate_str_to_create(input, delim);
// 	cr_assert_eq(got, want, "got %d, want %d", got, want);
// }
