/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:57:06 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 10:03:39 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->arr[y / PIXELS][x / PIXELS];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.player_down1, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.exit, x, y);
	else if (type == '1')
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.wall, x, y);
}

void	print_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			map_type(map, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
}

void	print_moves(t_map *map)
{
	char	*str;
	char	*moves_str;

	str = ft_itoa(map->moves);
	if (!str)
		return ;
	moves_str = ft_strjoin("Moves: ", str);
	if (!moves_str)
	{
		free(str);
		return ;
	}
	mlx_put_image_to_window(map->minilibx, map->window, map->image.wall, 0, 0);
	mlx_put_image_to_window(map->minilibx, map->window,
		map->image.wall, PIXELS, 0);
	mlx_put_image_to_window(map->minilibx, map->window,
		map->image.wall, PIXELS * 2, 0);
	mlx_string_put(map->minilibx, map->window, 10, 25, 0xFFFFFF, moves_str);
	free(str);
	free(moves_str);
}
