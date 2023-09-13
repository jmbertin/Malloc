#include "./libft.h"

/**
 * Outputs the string 's' to the given file descriptor.
 * @param	s	String to output.
 * @param	fd	File descriptor.
 */
void	ft_putstr_fd(char *s, int fd)
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
}
