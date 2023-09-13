#include "./libft.h"

/**
 * Creates a new list element with the provided content.
 * @param	content	Content to store in the new list element.
 * @return	Returns a new list element or NULL if the allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->next = 0;
	new->content = content;
	return (new);
}
