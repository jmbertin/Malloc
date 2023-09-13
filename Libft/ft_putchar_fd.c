#include "./libft.h"

/**
 * Outputs the character 'c' to the given file descriptor.
 * @param	c	Character to output.
 * @param	fd	File descriptor.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
