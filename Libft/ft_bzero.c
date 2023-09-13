#include "./libft.h"

/**
 * Sets n bytes of s to zero.
 * @param	s	Pointer to the block of memory to set to zero.
 * @param	n	Number of bytes to be set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str++ = '\0';
	}
}
