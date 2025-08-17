/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:04:18 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/11 10:04:20 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(t_map *map)
{
	size_t	size;

	size = ft_strlen(map->filename);
	if (size < 4)
		error_msg();
	if (map->filename[size - 1] != 'r')
		error_msg();
	if (map->filename[size - 2] != 'e')
		error_msg();
	if (map->filename[size - 3] != 'b')
		error_msg();
	if (map->filename[size - 4] != '.')
		error_msg();
	if (!ft_strnstr(map->filename, ".ber", size))
		error_msg();
}

void	check_size(t_map *map)
{
	int	y;
	int	x;
	int	max;

	if (!map->arr || !map->arr[0])
		error_msg2(map);
	y = 0;
	x = 0;
	max = ft_strlen(map->arr[y]);
	if (max == 0)
		error_msg2(map);
	while (y < map->y)
	{
		if (!map->arr[y])
			error_msg2(map);
		x = ft_strlen(map->arr[y]);
		if (max != x)
			error_msg2(map);
		y++;
	}
	map->x = max;
	if (map->x < 3 || map->y < 3)
		error_msg2(map);
}

void	check_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->x && map->arr[0][x] == '1')
		x++;
	if (x != map->x)
		error_msg2(map);
	y = 1;
	while (y < map->y)
	{
		if (map->arr[y][0] != '1' ||
				map->arr[y][map->x - 1] != '1')
			error_msg2(map);
		y++;
	}
	x = 0;
	while (x < map->x && map->arr[map->y - 1][x] == '1')
		x++;
	if (x != map->x)
		error_msg2(map);
}

void	check_parameters(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->arr[y][x] == 'C')
				map->c += 1;
			else if (map->arr[y][x] == 'E')
				map->e += 1;
			else if (map->arr[y][x] == 'P')
				map->p += 1;
			else if (map->arr[y][x] == '1' || map->arr[y][x] == '0')
				;
			else
				error_msg2(map);
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->e != 1 || map->p != 1)
		error_msg2(map);
}

void	check_map(t_map *map)
{
	check_file(map);
	map_array(map);
	check_size(map);
	check_wall(map);
	check_parameters(map);
	check_path(map);
	if (map->arr_copy)
	{
		free_arr(map->arr_copy, map->y);
		map->arr_copy = NULL;
	}
}
