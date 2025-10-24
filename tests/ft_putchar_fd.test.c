#include "libft.h"
#include <criterion/criterion.h>
#include "unistd.h"

Test(ft_putchar_fd_test, write_single_char)
{
	int fds[2];
	char c = 'A';
	char buf[2] = {0};

	cr_assert(pipe(fds) == 0, "Failed to create pipe");

	ft_putchar_fd(c, fds[1]);
	close(fds[1]);

	ssize_t bytes_read = read(fds[0], buf, 1);
	close(fds[0]);

	cr_assert_eq(bytes_read, 1, "Expected to read 1 byte, got %ld", bytes_read);
	cr_assert_eq(buf[0], c, "Expected '%c', got '%c'", c, buf[0]);
}
