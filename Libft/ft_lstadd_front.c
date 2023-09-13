#include "./libft.h"

/**
 * Adds the element 'new' at the beginning of the list.
 * @param	alst	Pointer to the beginning of the list.
 * @param	new		New element to add to the list.
 */
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new)
	{
		if (!alst)
			*alst = new;
		new->next = *alst;
		*alst = new;
	}
}
