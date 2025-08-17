/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:59:22 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/11 11:29:26 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_file_reading(t_map *map, int fd)
{
	if (fd != -1)
		close(fd);
	if (map->file)
	{
		free(map->file);
		map->file = NULL;
	}
	if (map->line)
	{
		free(map->line);
		map->line = NULL;
	}
}

void	cleanup_remaining_lines(int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(fd);
	}
}

void	read_file_lines(t_map *map, int fd)
{
	while (1)
	{
		map->line = get_next_line(fd);
		if (!map->line)
			break ;
		map->file = ft_strjoin2(map->file, map->line);
		free(map->line);
		map->line = NULL;
		if (!map->file)
		{
			cleanup_remaining_lines(fd);
			cleanup_file_reading(map, fd);
			error_msg();
		}
		map->y++;
	}
}

void	read_file_to_string(t_map *map)
{
	int	fd;
	int	len;

	map->y = 0;
	map->line = NULL;
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		error_msg();
	read_file_lines(map, fd);
	close(fd);
	if (!map->file || ft_strlen(map->file) == 0)
		error_msg();
	if (map->file && ft_strlen(map->file) > 0)
	{
		len = ft_strlen(map->file);
		if (map->file[len - 1] == '\n')
		{
			free(map->file);
			map->file = NULL;
			error_msg();
		}
	}
}

void	map_array(t_map *map)
{
	int	rows_count;

	rows_count = 0;
	read_file_to_string(map);
	map->arr = ft_split(map->file, '\n');
	map->arr_copy = ft_split(map->file, '\n');
	if (!map->arr || !map->arr_copy)
	{
		cleanup_file_reading(map, -1);
		free_both(map->arr, map->arr_copy, map->y);
		error_msg();
	}
	while (map->arr[rows_count])
		rows_count++;
	if (rows_count != map->y)
	{
		free_both(map->arr, map->arr_copy, rows_count);
		free(map->file);
		map->file = NULL;
		error_msg();
	}
	free(map->file);
	map->file = NULL;
}
