#include "./libft.h"

/**
 * Applies the function 'f' to each character of the string at a specific index.
 * @param	s	String to iterate through.
 * @param	f	Function to apply to each character at its index.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, s + i);
			i++;
		}
	}
}
