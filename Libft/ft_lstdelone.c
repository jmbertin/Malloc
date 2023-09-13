#include "./libft.h"

/**
 * Frees the memory of 'lst' and applies the function 'del' to its content.
 * @param	lst		Element to free.
 * @param	del		Function to apply to the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
