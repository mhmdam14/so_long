/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:56:06 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 14:02:13 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_collectibles(int x, int y, t_map *map)
{
	char	type;

	if (x < 0 || y < 0 || x >= map->x || y >= map->y
		|| map->arr_copy[y][x] == '1')
		return ;
	type = map->arr_copy[y][x];
	if (type == 'E')
		return ;
	if (type == 'C')
	{
		map->c_check -= 1;
		map->arr_copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map->arr_copy[y][x] = '1';
	flood_fill_collectibles(x + 1, y, map);
	flood_fill_collectibles(x - 1, y, map);
	flood_fill_collectibles(x, y + 1, map);
	flood_fill_collectibles(x, y - 1, map);
}

void	flood_fill_exit(int x, int y, t_map *map)
{
	char	type;

	if (x < 0 || y < 0 || x >= map->x || y >= map->y
		|| map->arr_copy[y][x] == '1')
		return ;
	type = map->arr_copy[y][x];
	if (type == 'E')
	{
		map->e_check -= 1;
		map->arr_copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P' || type == 'C')
		map->arr_copy[y][x] = '1';
	flood_fill_exit(x + 1, y, map);
	flood_fill_exit(x - 1, y, map);
	flood_fill_exit(x, y + 1, map);
	flood_fill_exit(x, y - 1, map);
}

void	path_failure(t_map *map)
{
	write(2, "Error\n", 6);
	if (map->arr)
		free_arr(map->arr, map->y);
	if (map->arr_copy)
		free_arr(map->arr_copy, map->y);
	if (map->file)
		free(map->file);
	exit(EXIT_FAILURE);
}

char	**duplicate_map(char **original, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			free_arr(copy, i);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	check_path(t_map *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	scan_player(map);
	flood_fill_collectibles(map->player.x, map->player.y, map);
	if (map->c_check != 0)
		path_failure(map);
	free_arr(map->arr_copy, map->y);
	map->arr_copy = NULL;
	map->arr_copy = duplicate_map(map->arr, map->y);
	flood_fill_exit(map->player.x, map->player.y, map);
	if (map->e_check != 0)
		path_failure(map);
}
