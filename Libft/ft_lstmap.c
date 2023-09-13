#include "./libft.h"

/**
 * Transforms each element's content using the function 'f', and creates a new list out of the results.
 * If memory allocation fails or if 'del' is needed, it will be applied to delete the content.
 * @param	lst		Beginning of the list.
 * @param	f		Function to transform content of an element.
 * @param	del		Function to delete content if necessary.
 * @return	Returns the new list or NULL if memory allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*temp2;

	if (!lst || !f || !del)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	temp = new;
	lst = lst->next;
	while (lst)
	{
		temp2 = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		temp->next = temp2;
		temp = temp2;
		lst = lst->next;
	}
	return (new);
}
