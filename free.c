#include "includes/malloc.h"

/**
 * Free the memory associated with the provided pointer.
 * If the pointer is null or already freed, the function returns immediately.
 * Otherwise, it releases the associated block, merges it with adjacent free blocks,
 * and checks if the entire zone can be released.
 * @param	ptr	Pointer to the memory block to be freed.
 */
static void	ft_free(void *ptr)
{
	if (!ptr)
		return;

	t_block *block = (t_block *)((char *)ptr - sizeof(t_block));

	if (block->free)
		return;

	t_zone *zone = ft_find_zone(block);
	if (!zone)
		return;

	block->free = 1;
	zone->free_size += block->size + sizeof(t_block);

	ft_merge_next(block, zone);
	ft_merge_prev(block, zone);
	ft_remove_if_last_block(zone, block);
	ft_release_memory(zone);
}

/**
 * Thread-safe version of ft_free. Frees the memory associated with the provided pointer.
 * Uses mutex locks to ensure safe memory deallocation in a multithreaded environment.
 * @param	ptr	Pointer to the memory block to be freed.
 */
void	free(void *ptr)
{
	pthread_mutex_lock(&g_malloc_mutex);
	ft_free(ptr);
	pthread_mutex_unlock(&g_malloc_mutex);
}
