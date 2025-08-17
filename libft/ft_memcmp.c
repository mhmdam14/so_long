/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:58:42 by mal-moha          #+#    #+#             */
/*   Updated: 2025/05/27 10:04:42 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*x1;
	const unsigned char	*x2;

	i = 0;
	x1 = (const unsigned char *)s1;
	x2 = (const unsigned char *)s2;
	while (i < n && x1[i] == x2[i])
		i++;
	if (i == n)
		return (0);
	return (x1[i] - x2[i]);
}
