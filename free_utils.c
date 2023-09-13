#include "includes/malloc.h"

/**
 * Check if the provided zone is the last of its type.
 * @param	zone	Pointer to the zone to be checked.
 * @return	Returns 1 if it's the last zone of its type, 0 otherwise.
 */
static int	free_is_last_zone(t_zone *zone)
{
	t_zone	*current_zone = zone;
	int	i = 0;
	int	type = current_zone->type;

	if (current_zone->type == LARGE_TYPE)
		return (0);
	while (current_zone)
	{
		if (current_zone->type == type)
			i++;
		current_zone = current_zone->next;
	}
	if (i == 1)
		return (1);
	return (0);
}

/**
 * Merge the block with its preceding block if the latter is free.
 * @param	block	Pointer to the block to be merged.
 * @param	zone	Pointer to the zone in which the block exists.
 */
void	ft_merge_prev(t_block *block, t_zone *zone)
{
	if (block->prev && block->prev->free)
	{
		block->prev->next = block->next;
		if (block->next)
			block->next->prev = block->prev;
		block->prev->size += block->size + sizeof(t_block);
		block = block->prev;
		zone->block_count--;
	}
}

/**
 * Merge the block with its succeeding block if the latter is free.
 * @param	block	Pointer to the block to be merged.
 * @param	zone	Pointer to the zone in which the block exists.
 */
void	ft_merge_next(t_block *block, t_zone *zone)
{
	if (block && block->next && block->next->free)
	{
		block->size += block->next->size + sizeof(t_block);
		if (block->next && block->next->next)
			block->next->next->prev = block;
		block->next = block->next->next;
		zone->block_count--;
	}
}

/**
 * Identify and return the zone that contains the provided block.
 * @param	block	Pointer to the block whose zone is to be found.
 * @return	Returns a pointer to the zone if found, NULL otherwise.
 */
void	*ft_find_zone(t_block *block)
{
	t_zone *zone = g_zone;

	while (zone)
	{
		if ((char*)block > (char*)zone && (char*)block < ((char*)zone + zone->total_size))
			break;
		zone = zone->next;
	}

	if (!zone)
		return (NULL);
	else
		return (zone);
}

/**
 * If the block is the last and is free, remove it from the zone.
 * @param	zone	Pointer to the zone containing the block.
 * @param	block	Pointer to the block to be potentially removed.
 */
void	ft_remove_if_last_block(t_zone *zone, t_block *block)
{
	if (block->free && !block->next)
	{
		if (block->prev)
			block->prev->next = NULL;
		zone->block_count--;
		zone->free_size += block->size + sizeof(t_block);
	}
}

/**
 * Release the memory of a zone if it's empty and not the last of its type.
 * @param	zone	Pointer to the zone to be potentially released.
 */
void	ft_release_memory(t_zone *zone)
{
	if (!zone->block_count)
	{
		if (zone->prev)
			zone->prev->next = zone->next;
		if (zone->next)
			zone->next->prev = zone->prev;
		if (!free_is_last_zone(zone))
		{
			if (zone == g_zone)
				g_zone = zone->next;
			munmap(zone, zone->total_size);
		}
	}
}
