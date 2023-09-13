#include "./libft.h"

/**
 * Compares the first num bytes of the block of memory pointed to by ptr1 to the first
 * num bytes pointed to by ptr2, returning zero if they all match or a value different
 * from zero representing which is greater if they do not.
 * @param	ptr1	Pointer to the first memory block.
 * @param	ptr2	Pointer to the second memory block.
 * @param	num	Number of bytes to be compared.
 * @return	Returns an integer less than, equal to, or greater than zero.
 */
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;

	i = 0;
	if (!num)
		return (0);
	while (i < num)
	{
		if (((unsigned char *)ptr1)[i] != ((unsigned char *)ptr2)[i])
		{
			return (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i]);
		}
		i++;
	}
	return (0);
}
