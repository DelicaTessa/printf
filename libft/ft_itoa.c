/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 13:35:24 by tclement      #+#    #+#                 */
/*   Updated: 2020/09/28 12:55:56 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	converse_int(long long n)
{
	return (n + '0');
}

static char	*splitnbrs(char *str, long long n, size_t index)
{
	size_t idx;

	idx = 0;
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	else
		n = n * -1;
	while (n != 0)
	{
		str[index - idx] = converse_int(-(n % 10));
		n /= 10;
		idx++;
	}
	return (str);
}

char		*ft_itoa(long long n)
{
	char	*str;
	size_t	index;
	int		count;

	index = 0;
	count = n;
	if (n <= 0)
		index++;
	while (count != 0)
	{
		index++;
		count /= 10;
	}
	str = ft_calloc(index + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	splitnbrs(str, n, index - 1);
	str[index] = '\0';
	return (str);
}
