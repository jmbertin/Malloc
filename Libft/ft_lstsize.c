#include "./libft.h"

/**
 * Counts the number of elements in the list.
 * @param	lst		Beginning of the list.
 * @return	Returns the number of elements in the list.
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst-> next;
		i++;
	}
	return (i);
}
