#include "./libft.h"

/**
 * Moves n bytes from memory area source to memory area destination.
 * Handles overlap.
 * @param	destination	Pointer to the destination memory area.
 * @param	source	Pointer to the source memory area.
 * @param	size	Number of bytes to be moved.
 * @return	Returns a pointer to destination.
 */
void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	if (!destination && !source)
		return (destination);
	if (source < destination)
	{
		while (size--)
			d[size] = s[size];
	}
	else
	{
		while (size--)
			*d++ = *s++;
	}
	return (destination);
}
