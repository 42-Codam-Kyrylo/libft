#include "libft.h"
#include <criterion/criterion.h>
#include <string.h>
#include <unistd.h>

static void	test_number(int n, const char *expected)
{
	int		fds[2];
	ssize_t	bytes_read;

	char buf[20] = {0}; 
	cr_assert(pipe(fds) == 0, "Failed to create pipe");
	ft_putnbr_fd(n, fds[1]);
	close(fds[1]);
	bytes_read = read(fds[0], buf, sizeof(buf) - 1);
	close(fds[0]);
	cr_assert_str_eq(buf, expected, "Expected '%s', got '%s'", expected, buf);
	cr_assert_eq(bytes_read, (ssize_t)strlen(expected), "Expected to read \
		%zu bytes, got %ld", strlen(expected), bytes_read);
}

Test(ft_putnbr_fd_test, positive_number)
{
	test_number(1008, "1008");
}

Test(ft_putnbr_fd_test, negative_number)
{
	test_number(-42, "-42");
}

Test(ft_putnbr_fd_test, zero)
{
	test_number(0, "0");
}

Test(ft_putnbr_fd_test, int_min)
{
	test_number(-2147483648, "-2147483648");
}

Test(ft_putnbr_fd_test, int_max)
{
	test_number(2147483647, "2147483647");
}
