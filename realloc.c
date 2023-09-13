#include "includes/malloc.h"

/**
 * Reallocation of a memory block pointed by ptr to 'size' bytes.
 * - If ptr is NULL, the call is equivalent to malloc(size).
 * - If size is zero, the call is equivalent to free(ptr).
 * - If ptr is not NULL, it checks if the block pointed by ptr is large
 *   enough to hold the new contents. If the block is large enough, it returns
 *   the same pointer. Otherwise, it allocates a new block, copies the old
 *   contents, frees the old block, and returns a pointer to the new block.
 * @param	ptr		Pointer to the memory block to be reallocated.
 * @param	size	The new size for the memory block.
 * @return	Returns a pointer to the reallocated memory block or NULL if
 *          reallocation fails.
 */
void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	int		tomove = 0;
	t_block	*block;

	if (!ptr)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	block = (t_block*)((char*)ptr - sizeof(t_block));
	if (block->size == size)
		return (ptr);

	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);

	if (size < block->size)
		tomove = size;
	else
		tomove = block->size;

	ft_memmove(new_ptr, ptr, tomove);
	free(ptr);
	return (new_ptr);
}
