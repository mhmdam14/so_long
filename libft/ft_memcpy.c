/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:39:10 by mal-moha          #+#    #+#             */
/*   Updated: 2025/05/19 16:05:25 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	i = 0;
	s1 = dest;
	s2 = src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
