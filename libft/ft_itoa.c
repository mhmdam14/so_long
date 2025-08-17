/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:20:15 by mal-moha          #+#    #+#             */
/*   Updated: 2025/05/27 10:04:22 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	initializer(int *i, long *nbr, int n)
{
	*nbr = (long)n;
	*i = count_digits(*nbr);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nbr;
	char	*res;

	initializer(&i, &nbr, n);
	res = malloc (sizeof(char) * (count_digits(nbr) + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	if (nbr == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		res[--i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
