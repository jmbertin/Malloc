#include "includes/malloc.h"
#include <stdio.h>

/**
 * Display the allocated memory blocks.
 * This function iterates through all the zones and their corresponding blocks.
 * It then prints the details of the allocated blocks (non-free ones) including
 * their address and sizes. It also shows the type of the zone (TINY, SMALL, LARGE).
 * At the end, it prints the total bytes of memory that have been allocated.
 */
void	show_alloc_mem(void)
{
	t_zone	*zone = g_zone;
	t_block	*first_block, *current_block;
	size_t	total = 0;

	while (zone)
	{
		if (zone->type == TINY_TYPE)
			ft_printf("TINY : ");
		else if (zone->type == SMALL_TYPE)
			ft_printf("SMALL : ");
		else
			ft_printf("LARGE : ");
		ft_printf("%p\n", (void *)zone);
		first_block = (t_block *)((char *)zone + sizeof(t_zone));
		current_block = first_block;
		while (current_block)
		{
			if (!current_block->free)
			{
				printf("%p - %p : %ld bytes\n", (void *)current_block, (void *)((char *)current_block + current_block->size), current_block->size);
				total += current_block->size;
			}
			current_block = current_block->next;
			if (current_block == first_block)
				break ;
		}
		zone = zone->next;
	}
	printf("Total : %ld bytes\n", total);
}
