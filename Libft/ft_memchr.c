#include "./libft.h"

/**
 * Searches for the first occurrence of the character searchedChar in the first size bytes
 * of the memory area pointed to by memoryBlock.
 * @param	memoryBlock	Pointer to the memory block to be searched.
 * @param	searchedChar	Character to be located.
 * @param	size	Number of bytes to be searched.
 * @return	Returns a pointer to the located character, or NULL if the character does not appear.
 */
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (unsigned char *)memoryBlock;
	while (size--)
	{
		if (src[i] == (unsigned char)searchedChar)
			return (src + i);
		i++;
	}
	return (NULL);
}
