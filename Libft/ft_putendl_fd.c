#include "./libft.h"

/**
 * Outputs the string 's' followed by a newline to the given file descriptor.
 * @param	s	String to output.
 * @param	fd	File descriptor.
 */
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
