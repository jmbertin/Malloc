#include "./libft.h"

/**
 * Locates the first occurrence of to_find in str, where not more than len characters are searched.
 * @param	str	String to be searched.
 * @param	to_find	Substring to be located.
 * @param	len	Number of characters to be searched.
 * @return	Returns a pointer to the first character of the first occurrence, or NULL if the substring is not found.
 */
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0 ;
	j = 0 ;
	if (!str && len == 0)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		if (to_find[0] == str[i])
		{
			j = 0;
			while (to_find[j] == str[i + j] && i + j < len)
			{
				if (to_find[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
