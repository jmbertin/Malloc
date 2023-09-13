#include "includes/malloc.h"

/**
 * Determine the zone type based on the given size.
 * @param	size	The size for which we need to determine the zone type.
 * @return	Returns the type of zone: TINY_TYPE, SMALL_TYPE, or LARGE_TYPE.
 */
static int	determine_zone_type(size_t size)
{
	if (size <= TINY_MAX)
		return (TINY_TYPE);
	else if (size <= SMALL_MAX)
		return (SMALL_TYPE);
	else
		return (LARGE_TYPE);
}

/**
 * Get the total size of the zone based on the provided size.
 * @param	size	The block size to be allocated.
 * @return	Returns the total size of the corresponding zone.
 */
static int ft_get_total_size(size_t size)
{
	if (size <= TINY_MAX)
		return (TINY_ZONE);
	else if (size <= SMALL_MAX)
		return (SMALL_ZONE);
	else
		return (size + sizeof(t_zone) + sizeof(t_block));
}

/**
 * Initialize and create a new memory zone based on the given size.
 * @param	size	The size for which the zone should be initialized.
 * @return	Returns a pointer to the newly initialized zone.
 */
static t_zone	*initialize_zone(size_t size)
{
	size_t	total_size;
	int		type;

	size = (size + 7) & ~7;
	type = determine_zone_type(size);
	total_size = ft_get_total_size(size);

	t_zone *new_zone = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (new_zone == MAP_FAILED)
		return (NULL);

	new_zone->type = type;
	new_zone->total_size = total_size;
	new_zone->free_size = total_size - sizeof(t_zone);
	new_zone->block_count = 0;
	new_zone->next = NULL;
	new_zone->prev = NULL;

	if (!g_zone)
		g_zone = new_zone;
	else
	{
		t_zone *tmp = g_zone;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_zone;
		new_zone->prev = tmp;
	}

	return (new_zone);
}

/**
 * Search for a zone that fits the provided size.
 * If no appropriate zone is found, initializes a new one.
 * @param	current_zone	Current zone to start the search from.
 * @param	size			The size for which we need to find or create a zone.
 * @return	Returns a pointer to a zone that can fit the size.
 */
static t_zone	*ft_search_zone(t_zone	*current_zone, int size)
{
	current_zone = g_zone;
	while (current_zone)
	{
		if (current_zone->type == determine_zone_type(size) && current_zone->free_size >= size + sizeof(t_block))
			break ;
		current_zone = current_zone->next;
	}
	if (!current_zone)
		current_zone = initialize_zone(size);
	return (current_zone);
}

/**
 * Create and initialize a new block inside the provided zone.
 * @param	zone			The zone where the block should be created.
 * @param	current_block	A pointer to the current block.
 * @param	size			The size for which the block should be initialized.
 * @return	Returns a pointer to the newly created block.
 */
static t_block	*ft_create_block(t_zone *zone, t_block *current_block, size_t size)
{
	current_block = (t_block *)(zone + 1);
	current_block->size = size;
	current_block->free = 0;
	current_block->next = current_block;
	current_block->prev = current_block;
	zone->block_count++;
	zone->free_size -= size + sizeof(t_block);
	return (current_block);
}

/**
 * Attempt to allocate a new block at the end of the specified zone.
 * @param	first_block	Pointer to the first block in the zone.
 * @param	last_block	Pointer to the last block in the zone.
 * @param	new_block	Pointer where the new block should be initialized.
 * @param	zone		Zone in which allocation is attempted.
 * @param	size		The size to be allocated.
 * @return	Returns a pointer to the newly allocated block or NULL if allocation fails.
 */
t_block	*ft_try_allocate_endzone(t_block *first_block, t_block *last_block, t_block *new_block, t_zone *zone, size_t size)
{
	new_block->size = size;
	new_block->free = 0;
	new_block->next = first_block;
	new_block->prev = last_block;
	last_block->next = new_block;
	first_block->prev = new_block;
	zone->block_count++;
	zone->free_size -= size + sizeof(t_block);
	return (new_block);
}

/**
 * Split a block into two separate blocks.
 * @param	current_block	Block to be split.
 * @param	zone			Zone in which the block resides.
 * @param	size			Size to which the block should be split.
 */
void	ft_split_blocks(t_block *current_block, t_zone *zone, size_t size)
{
	t_block *next_block = (t_block *)((char *)current_block + sizeof(t_block) + size);
	next_block->size = current_block->size - size - sizeof(t_block);
	next_block->free = 1;
	next_block->next = current_block->next;
	next_block->prev = current_block;

	current_block->next->prev = next_block;
	current_block->next = next_block;
	zone->block_count++;
}

/**
 * Search for a block in a zone that fits the provided size.
 * If no block is found, tries to allocate a new block in the zone.
 * @param	zone	Zone in which to search for a block.
 * @param	size	Size for which we need to find or create a block.
 * @return	Returns a pointer to a block that fits the size or NULL if not found.
 */
t_block	*find_block_in_zone(t_zone *zone, size_t size)
{
	t_block			*current_block = NULL;
	unsigned int	blocks_checked = 0;

	if (zone->block_count == 0)
		return (ft_create_block(zone, current_block, size));

	t_block			*first_block = (t_block *)(zone + 1);
	current_block = first_block;
	while (blocks_checked < zone->block_count)
	{
		if (current_block->free && current_block->size >= size)
		{
			if (current_block->size > size + sizeof(t_block) + (sizeof(t_block)))
				ft_split_blocks(current_block, zone, size);
			current_block->size = size;
			zone->free_size -= size + sizeof(t_block);
			current_block->free = 0;
			return (current_block);
		}
		current_block = current_block->next;
		blocks_checked++;
	}
	t_block *last_block = current_block->prev;
	t_block *new_block = (t_block *)((char *)last_block + sizeof(t_block) + last_block->size);
	if ((char *)new_block + sizeof(t_block) + size <= (char *)zone + zone->total_size)
		return(ft_try_allocate_endzone(first_block, last_block, new_block, zone, size));
	return (NULL);
}

/**
 * Attempt to allocate memory for the given size.
 * @param	size	The size for which memory should be allocated.
 * @return	Returns a pointer to the allocated memory or NULL if allocation fails.
 */
void	*ft_allocate(size_t size)
{
	t_zone	*current_zone = NULL;
	t_block			*block = NULL;

	size = (size + 7) & ~7;
	current_zone = ft_search_zone(current_zone, size);
	block = find_block_in_zone(current_zone, size);

	return (block ? (void *)(block + 1) : NULL);
}
