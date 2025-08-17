/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:04:36 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 10:04:37 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buf)
{
	int		len;
	int		i;
	char	*line;

	i = 0;
	len = get_line_len(buf);
	if (!buf || !buf[0])
		return (NULL);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*alloc(char *buf, int i)
{
	int		j;
	char	*new_buf;

	j = 0;
	new_buf = malloc(sizeof(char) * (ft_strlen(buf + i) + 1));
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	while (buf[i])
		new_buf[j++] = buf[i++];
	new_buf[j] = '\0';
	free(buf);
	return (new_buf);
}

char	*update_buff(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i++])
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	if (!buf[i])
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	return (alloc(buf, i));
}

int	read_to_buff(int fd, char **buf, char *temp)
{
	int		b;
	char	*tmp;

	b = 1;
	while (b > 0 && !ft_strchr(*buf, '\n'))
	{
		b = read(fd, temp, BUFFER_SIZE);
		if (b == -1)
			return (-1);
		temp[b] = '\0';
		tmp = ft_strjoin(*buf, temp);
		if (*buf)
			free(*buf);
		*buf = tmp;
		if (!*buf)
			return (-1);
	}
	return (b);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*temp;
	char		*line;
	int			b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	b = read_to_buff(fd, &buf, temp);
	free(temp);
	if (b == -1 || !buf || !buf[0])
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	line = get_line(buf);
	buf = update_buff(buf);
	return (line);
}
