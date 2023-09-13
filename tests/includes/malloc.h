#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>
# include "libft.h"
# include <pthread.h>

/*
	Define types of memory zones
	Pagesize (system) : 4096 bytes
	Alignment: 8 bytes
	TINY_ZONE : 16384 bytes (4 pages)
	SMALL_ZONE : 106496 bytes (26 pages)
	LARGE_ZONE : varying size (size + sizeof(t_zone) + sizeof(t_block))
*/
# define TINY_TYPE 1
# define TINY_MAX 128
# define TINY_ZONE (4 * getpagesize())
# define SMALL_TYPE 2
# define SMALL_MAX 1024
# define SMALL_ZONE (26 * getpagesize())
# define LARGE_TYPE 3

/*
	Memory zone structure
	Zone structure size = 48 bytes
*/
typedef struct	s_zone
{
	struct s_zone	*prev;
	struct s_zone	*next;
	int						type;
	size_t					total_size;
	size_t					free_size;
	size_t					block_count;
}				t_zone;

/*
	Block structure
	Block structure size = 32 bytes
*/
typedef struct	s_block
{
	size_t			size;
	int				free;
	struct s_block	*next;
	struct s_block	*prev;
}				t_block;

extern pthread_mutex_t	g_malloc_mutex;
extern t_zone			*g_zone;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

// MALLOC UTILS
void			*ft_allocate(size_t size);

// FREE UTILS
void			ft_merge_prev(t_block *block, t_zone *zone);
void			ft_merge_next(t_block *block, t_zone *zone);
void			*ft_find_zone(t_block *block);
void			ft_remove_if_last_block(t_zone *zone, t_block *block);
void			ft_release_memory(t_zone *zone);

#endif
