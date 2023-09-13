#include "./libft.h"

/**
 * Allocates memory for an array of elementCount elements, each of elementSize bytes, and initializes all bytes to zero.
 * @param	elementCount	Number of elements.
 * @param	elementSize	Size of each element.
 * @return	Returns a pointer to the allocated memory.
 */
void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*dest;

	dest = (void *)malloc(elementCount * elementSize);
	if (dest == 0 || elementCount == SIZE_MAX || elementSize == SIZE_MAX)
		return (NULL);
	ft_bzero(dest, elementCount * elementSize);
	return (dest);
}
