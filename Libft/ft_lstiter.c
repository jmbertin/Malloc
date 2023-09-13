#include "./libft.h"

/**
 * Iterates the list 'lst' and applies the function 'f' to the content of each element.
 * @param	lst		Beginning of the list.
 * @param	f		Function to apply to each element's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst-> next;
		}
	}
}
