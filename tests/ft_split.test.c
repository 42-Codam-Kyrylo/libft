#include "libft.h"
#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdio.h>

// static void print_string_arrays(char **strs, char *label);
static void compare_strings(char **got, char **want);

Test(ft_split_test, basic_split)
{
	char *input = "Hello,world,how,are,you";
	char *want[] = {"Hello", "world", "how", "are", "you", NULL};
	char delim = ',';

	char **got = ft_split(input, delim);

	compare_strings(got, want);
}
Test(ft_split_test, single_word)
{
	char *input = "Hello";
	char *want[] = {"Hello", NULL};
	char delim = ',';

	char **got = ft_split(input, delim);

	compare_strings(got, want);
}

Test(ft_split_test, only_delimiter)
{
	char *input = ",,,,";
	char *want[] = {NULL};
	char delim = ',';

	char **got = ft_split(input, delim);

	compare_strings(got, want);
}
Test(ft_split_test, delimiters_at_edges)
{
	char *input = ",a,b,";
	char *want[] = {"a", "b", NULL};
	char delim = ',';

	char **got = ft_split(input, delim);

	compare_strings(got, want);
}
Test(ft_split_test, empty_string)
{
	char *input = "";
	char *want[] = {NULL};
	char delim = ',';

	char **got = ft_split(input, delim);

	compare_strings(got, want);
}
Test(ft_split_test, multiple_delimeters)
{
	char *input = "Hello,,,how,are,you";
	char *want[] = {"Hello", "how", "are", "you", NULL};
	char delim = ',';

	char **got = ft_split(input, delim);

	compare_strings(got, want);
}

static void compare_strings(char **got, char **want)
{
	// print_string_arrays(got, "got ");
	// print_string_arrays(want, "want");
	fflush(stdout);

	int i = 0;
	while (got[i] && want[i])
	{
		cr_assert_str_eq(got[i], want[i],
						 "Mismatch at index %d: got [%s], want [%s]",
						 i, got[i], want[i]);
		i++;
	}
	cr_assert_null(got[i], "Got more strings than expected at index %d", i);
	cr_assert_null(want[i], "Expected more strings than got at index %d", i);
	i = 0;
	while (got[i])
	{
		free(got[i]);
		i++;
	}
	free(got);
}
// static void print_string_arrays(char **strs, char *label)
// {
// 	printf("%s: ", label);

// 	int i = 0;
// 	while (strs[i])
// 	{
// 		printf("[%s]", strs[i]);
// 		if (strs[i + 1])
// 			printf(", ");
// 		i++;
// 	}
// 	printf(", [NULL]\n");
// 	fflush(stdout);
// }

// struct split_test_case
// {
// 	char *name;
// 	char *input;
// 	char delim;
// 	char **want;
// };

// ParameterizedTestParameters(ft_split_test, table_driven)
// {
// 	static char *case1[] = {"Hello", "world", "how", "are", "you", NULL};
// 	static char *case2[] = {"Hello", NULL};
// 	static char *case3[] = {NULL};
// 	static char *case4[] = {"one", "two", "three", NULL};
// 	static char *case5[] = {"test", NULL};

// 	static struct split_test_case cases[] = {
// 		{"basic split", "Hello,world,how,are,you", ',', case1},
// 		{"single word", "Hello", ',', case2},
// 		{"empty string", "", ',', case3},
// 		{"multiple delimiters", "one,,two,,,three", ',', case4},
// 		{"no delimiters", "test", ',', case5},
// 	};

// 	size_t nb_params = sizeof(cases) / sizeof(struct split_test_case);
// 	return cr_make_param_array(struct split_test_case, cases, nb_params);
// 	// return (cr_make_param_array(struct split_test_case, cases, sizeof(cases) / sizeof(cases[0])));
// }

// ParameterizedTest(struct split_test_case *tc, ft_split_test, table_driven)
// {
// 	char **got = ft_split(tc->input, tc->delim);

// 	printf("\nTest: %s\n", tc->name);
// 	printf("Input: `%s`, delim: `%c`\n", tc->input, tc->delim);

// 	cr_assert_not_null(got, "ft_split returned NULL");

// 	int i = 0;
// 	while (tc->want[i] && got[i])
// 	{
// 		cr_assert_str_eq(got[i], tc->want[i], "Mismatch at index %d", i);
// 		i++;
// 	}

// 	cr_assert_null(got[i], "Got more strings than expected");
// 	cr_assert_null(tc->want[i], "Expected more strings than got");

// 	i = 0;
// 	if (got != NULL)
// 	{
// 		while (got[i])
// 		{
// 			free(got[i]);
// 			i++;
// 		}
// 		free(got);
// 	}
// }