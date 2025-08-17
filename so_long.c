/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:57:00 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 10:36:36 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map, char **argv)
{
	map->filename = argv[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->x = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->fd = -1;
	map->line = NULL;
	map->file = NULL;
	map->arr = NULL;
	map->arr_copy = NULL;
	map->minilibx = NULL;
	map->window = NULL;
	map->image.empty = NULL;
	map->image.exit = NULL;
	map->image.collectible = NULL;
	map->image.wall = NULL;
	map->image.player_left1 = NULL;
	map->image.player_right1 = NULL;
	map->image.player_up1 = NULL;
	map->image.player_down1 = NULL;
}

int	handle_mlx_init_error(t_map *map)
{
	write(2, "Error\nMLX initialization failed\n", 33);
	if (map->arr)
		free_arr(map->arr, map->y);
	if (map->arr_copy)
		free_arr(map->arr_copy, map->y);
	exit(EXIT_FAILURE);
	return (1);
}

int	handle_window_error(t_map *map)
{
	write(2, "Error\nWindow creation failed\n", 30);
	if (map->minilibx)
	{
		mlx_destroy_display(map->minilibx);
		free(map->minilibx);
	}
	if (map->arr)
		free_arr(map->arr, map->y);
	if (map->arr_copy)
		free_arr(map->arr_copy, map->y);
	exit(EXIT_FAILURE);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	initialize_map(&map, argv);
	check_map(&map);
	map.minilibx = mlx_init();
	if (!map.minilibx)
		return (handle_mlx_init_error(&map));
	map.window = mlx_new_window(map.minilibx,
			map.x * PIXELS, map.y * PIXELS, "so_long");
	if (!map.window)
		return (handle_window_error(&map));
	file_to_image(&map);
	print_map(&map);
	mlx_hook(map.window, 17, 0, end, &map);
	mlx_key_hook(map.window, key_hook, &map);
	mlx_loop(map.minilibx);
	return (0);
}
