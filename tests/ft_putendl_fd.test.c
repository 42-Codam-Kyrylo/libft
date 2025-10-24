#include "libft.h"
#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>

Test(ft_putendl_fd_test, write_word)
{
	int fds[2];
	char str[] = "Helo world!";
	char expected[] = "Helo world!\n";
	char buf[20] = {0};

	cr_assert(pipe(fds) == 0, "Failed to create pipe");

	ft_putendl_fd(str, fds[1]);
	close(fds[1]);

	ssize_t bytes_read = read(fds[0], buf, strlen(expected));
	close(fds[0]);

	cr_assert_eq(bytes_read, (ssize_t)strlen(expected),
				 "Expected to read %zu bytes, got %ld", strlen(expected), bytes_read);
	cr_assert_str_eq(buf, expected, "Expected '%s', got '%s'", expected, buf);
}

Test(ft_putendl_fd_test, null_string_does_not_crash)
{
	ft_putendl_fd(NULL, 1);
	cr_assert(1, "Function should not crash on NULL input");
}
