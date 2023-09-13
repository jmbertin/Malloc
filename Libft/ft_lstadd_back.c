#include "./libft.h"

/**
 * Adds the element 'new' at the end of the list.
 * @param	alst	Pointer to the beginning of the list.
 * @param	new		New element to add to the list.
 */
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp_list;

	if (new && alst)
	{
		if (!*alst)
		{
			*alst = new;
			return ;
		}
		tmp_list = ft_lstlast(*alst);
		tmp_list->next = new;
	}
}
