/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:24:11 by mal-moha          #+#    #+#             */
/*   Updated: 2025/05/27 10:05:37 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char const *s1, char const *set, int j)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[j] == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	initializer(char const *s1, int *start, int *end, int *i)
{
	*start = 0;
	*end = ft_strlen(s1) - 1;
	*i = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		end;

	initializer(s1, &start, &end, &i);
	while (s1[start] && is_sep(s1, set, start))
		start++;
	while (end >= start && is_sep(s1, set, end))
		end--;
	if (end < start)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
