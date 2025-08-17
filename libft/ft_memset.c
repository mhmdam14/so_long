/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:50:27 by mal-moha          #+#    #+#             */
/*   Updated: 2025/05/27 10:04:50 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*x;

	i = 0;
	x = s;
	while (i < n)
	{
		x[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
