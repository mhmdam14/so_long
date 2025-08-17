/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:57:44 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 10:03:15 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resume(t_map *map, int x, int y, int direction)
{
	if (direction == W)
		y -= 1;
	if (direction == S)
		y += 1;
	if (direction == A)
		x -= 1;
	if (direction == D)
		x += 1;
	if (map->arr[y][x] == 'E' && map->c == 0)
	{
		win_msg(map);
		return ;
	}
	if (map->arr[y][x] == 'C')
	{
		map->arr[y][x] = '0';
		map->c--;
	}
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x - 1 && map->arr[y][x + 1] != '1')
	{
		if (map->arr[y][x + 1] == 'E' && map->c > 0)
			return ;
		resume(map, x, y, D);
		map->moves++;
		print_moves(map);
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x * PIXELS, y * PIXELS);
		map->arr[y][x] = '0';
		x++;
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x * PIXELS, y * PIXELS);
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.player_right1, x * PIXELS, y * PIXELS);
		map->arr[y][x] = 'P';
		map->player.x = x;
	}
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->arr[y - 1][x] != '1')
	{
		if (map->arr[y - 1][x] == 'E' && map->c > 0)
			return ;
		resume(map, x, y, W);
		map->moves++;
		print_moves(map);
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x * PIXELS, y * PIXELS);
		map->arr[y][x] = '0';
		y--;
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x * PIXELS, y * PIXELS);
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.player_up1, x * PIXELS, y * PIXELS);
		map->arr[y][x] = 'P';
		map->player.y = y;
	}
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y - 1 && map->arr[y + 1][x] != '1')
	{
		if (map->arr[y + 1][x] == 'E' && map->c > 0)
			return ;
		resume(map, x, y, S);
		map->moves++;
		print_moves(map);
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x * PIXELS, y * PIXELS);
		map->arr[y][x] = '0';
		y++;
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x * PIXELS, y * PIXELS);
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.player_down1, x * PIXELS, y * PIXELS);
		map->arr[y][x] = 'P';
		map->player.y = y;
	}
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->arr[y][x - 1] != '1')
	{
		if (map->arr[y][x - 1] == 'E' && map->c > 0)
			return ;
		resume(map, x, y, A);
		map->moves++;
		print_moves(map);
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x * PIXELS, y * PIXELS);
		map->arr[y][x] = '0';
		x--;
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.empty, x * PIXELS, y * PIXELS);
		mlx_put_image_to_window(map->minilibx, map->window,
			map->image.player_left1, x * PIXELS, y * PIXELS);
		map->arr[y][x] = 'P';
		map->player.x = x;
	}
}
