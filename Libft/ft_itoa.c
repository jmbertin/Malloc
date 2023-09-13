#include "./libft.h"

/**
 * Calculates the number of digits required to represent an integer, including the sign for negative numbers.
 * This function determines how many characters are needed to print an integer in base 10.
 * For negative numbers, an additional character is considered for the '-' sign.
 * @param	a	The integer whose size needs to be determined.
 * @return	Returns the number of characters required to represent 'a', considering the sign for negatives.
 */
static int	ft_size_m(int a)
{
	unsigned long long int	i;
	unsigned long long int	b;

	i = 0;
	b = a;
	if (a < 0)
		b = -b;
	while (b > 9)
	{
		b = b / 10;
		i++;
	}
	if (a < 0)
		return ((int)i + 2);
	return ((int)i + 1);
}

/**
 * Converts an integer into a string.
 * @param	nb	Integer to convert.
 * @return	Returns the string representation of the integer or NULL if the allocation fails.
 */
char	*ft_itoa(int nb)
{
	char			*str;
	int				size;
	int				i;
	long long int	nb2;

	nb2 = nb;
	size = ft_size_m(nb2);
	i = size - 1;
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	if (nb2 < 0)
	{
		str[0] = '-';
		nb2 = -nb2;
	}
	while (nb2 > 9)
	{
		str[i] = (nb2 % 10 + '0');
		nb2 = nb2 / 10;
		i--;
	}
	str[i] = nb2 % 10 + '0';
	str[size] = '\0';
	return (str);
}
