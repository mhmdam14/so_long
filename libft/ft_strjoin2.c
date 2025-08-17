/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:04:06 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 10:04:07 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *str1, char *str2)
{
	char	*str;
	size_t	size1;
	size_t	size2;

	if (!str1)
	{
		str1 = malloc(sizeof(char));
		str1[0] = '\0';
	}
	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	str = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, str1, size1);
	ft_memcpy(str + size1, str2, size2 + 1);
	str[size1 + size2] = '\0';
	free(str1);
	return (str);
}
