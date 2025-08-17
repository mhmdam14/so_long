/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:04:20 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 10:04:29 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	copy_str(char *dst, char *src, int *i)
{
	int	j;

	j = 0;
	while (src && src[j])
		dst[(*i)++] = src[j++];
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	copy_str(res, s1, &i);
	copy_str(res, s2, &i);
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

int	get_line_len(char *buf)
{
	int	len;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (buf[len] == '\n')
		len++;
	return (len);
}
