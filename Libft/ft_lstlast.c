#include "./libft.h"

/**
 * Finds the last element of the list.
 * @param	lst		Beginning of the list.
 * @return	Returns the last element of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
