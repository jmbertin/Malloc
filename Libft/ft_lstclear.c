#include "./libft.h"

/**
 * Clears the content of the list, and free each element using the function 'del' and free.
 * @param	lst		Pointer to the beginning of the list.
 * @param	del		Function to delete content of a list element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
		*lst = NULL;
	}
}
