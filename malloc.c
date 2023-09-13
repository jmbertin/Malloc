#include "includes/malloc.h"

t_zone					*g_zone = NULL;
pthread_mutex_t	g_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

/**
 * Check if the provided size is greater than the system's memory limit.
 * @param	size	The size to be checked.
 * @return	Returns 1 if size is within the system's limit, 0 otherwise.
 */
static int	ft_get_systemlimit(size_t size)
{
	struct rlimit	rlp;

	if (getrlimit(RLIMIT_DATA, &rlp) == -1)
		return (0);
	if (size > (size_t)rlp.rlim_cur)
		return (0);
	return (1);
}

/**
 * Allocate memory of the provided size.
 * If size exceeds the system's memory limit or is non-positive, returns NULL.
 * @param	size	The size of memory to be allocated.
 * @return	Returns a pointer to the allocated memory or NULL if allocation fails.
 */
static void	*ft_malloc(size_t size)
{
	void	*ptr = NULL;

	if (size <= 0)
		return (NULL);

	if (!ft_get_systemlimit(size))
		return (NULL);

	ptr = ft_allocate(size);
	return (ptr);
}

/**
 * Thread-safe implementation of the malloc function.
 * Allocates memory of the provided size.
 * @param	size	The size of memory to be allocated.
 * @return	Returns a pointer to the allocated memory or NULL if allocation fails.
 */
void* malloc(size_t size)
{
	void* ptr = NULL;

	pthread_mutex_lock(&g_malloc_mutex);
	ptr = ft_malloc(size);
	pthread_mutex_unlock(&g_malloc_mutex);
	return (ptr);
}
