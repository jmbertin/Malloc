#include "./libft.h"

/**
 * Fills a block of memory with a specified value.
 * @param	s	Pointer to the block of memory to fill.
 * @param	c	Value to be set.
 * @param	n	Number of bytes to be set to the value.
 * @return	Returns a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = (unsigned char)c;
	return (s);
}
