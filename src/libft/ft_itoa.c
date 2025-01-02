/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:42:02 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/14 17:42:05 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_size(long nb)
{
	size_t	s;

	s = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		s = 1;
	}
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		s++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	size_t	j;
	char	*s;
	long	l_n;

	j = (count_size(n)) - 1;
	l_n = (long)n;
	s = (char *) malloc((count_size(l_n) + 1) * sizeof(char));
	if (!s)
		return (0);
	if (n < 0)
		l_n *= -1;
	while (l_n > 0)
	{
		s[j] = (char)((l_n % 10) + '0');
		l_n /= 10;
		j --;
	}
	if (n == 0)
		s[0] = '0';
	if (n < 0)
		s[j] = '-';
	s[count_size((long)n)] = '\0';
	return (s);
}
