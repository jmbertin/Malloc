#include "./libft.h"

/**
 * Checks for spaces and sign characters (+ or -) in the provided string and updates pointers for position and count.
 * Skips white-space characters (including tabs, newlines, vertical tabs, carriage returns, and form feeds)
 * and counts consecutive '+' and '-' signs in the string. The function returns early with a value of 9 if two
 * consecutive signs are found.
 * @param	ptr_i		Pointer to an integer where the final position of the check will be stored.
 * @param	str			Input string to check.
 * @param	ptr_minus	Pointer to an integer where the number of '-' signs will be stored.
 * @return	Returns 0 on successful check or 9 if two consecutive signs are found.
 */
static int	check_sp_signs(int *ptr_i, const char *str, int *ptr_minus)
{
	int	minus;
	int	i;

	i = 0;
	minus = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if ((str[i] == 43 || str[i] == 45)
		&& (str[i + 1] == 43 || str[i + 1] == 45))
		return (9);
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			minus++;
			i++;
		}
		else
			i++;
	}
	*ptr_i = i;
	*ptr_minus = minus;
	return (0);
}

/**
 * Converts the initial portion of str to an integer representation.
 * @param	str	Pointer to the string to be converted.
 * @return	Returns the converted integer.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	minus;

	i = 0;
	nb = 0;
	minus = 0;
	if (check_sp_signs(&i, str, &minus) == 9)
		return (0);
	while (str[i] && (str[i] > 47 && str[i] < 58))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (minus % 2 == 1)
		nb = -nb;
	return (nb);
}
