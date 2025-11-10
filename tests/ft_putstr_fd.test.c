#include "libft.h"
#include <criterion/criterion.h>
#include "unistd.h"
#include <string.h>

Test(ft_putstr_fd_test, write_word)
{
	int fds[2];
	char str[] = "Helo world!";
	char buf[12] = {0};

	cr_assert(pipe(fds) == 0, "Failed to create pipe");

	ft_putstr_fd(str, fds[1]);
	close(fds[1]);

	ssize_t bytes_read = read(fds[0], buf, strlen(str));
	close(fds[0]);

	cr_assert_eq(bytes_read, 11, "Expected to read 11 byte, got %ld", bytes_read);
	cr_assert_str_eq(buf, str, "Expected '%s', got '%s'", str, buf);
}

Test(ft_putstr_fd_test, null_string_does_not_crash)
{
	ft_putstr_fd(NULL, 1);
	cr_assert(1, "Function should not crash on NULL input");
}
