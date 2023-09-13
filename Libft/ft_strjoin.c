#include "./libft.h"

/**
 * Joins two strings into a new string.
 * @param	s1	First string.
 * @param	s2	Second string.
 * @return	Returns the new string or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	if (!s1 || !s2)
		return (0);
	res = (char *)malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == 0)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
