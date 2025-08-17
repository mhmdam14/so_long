/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmdam14 <mhmdam14@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:59:27 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/17 19:19:01 by mhmdam14         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image_player(t_map *map)
{
	int	a;

	a = PIXELS;
	map->image.player_right1 = mlx_xpm_file_to_image(map->minilibx,
			"Textures/right-1-40.xpm", &a, &a);
	if (!map->image.player_right1)
		exit_and_free(map, EXIT_FAILURE);
	map->image.player_up1 = mlx_xpm_file_to_image(map->minilibx,
			"Textures/up-1-40.xpm", &a, &a);
	if (!map->image.player_up1)
		exit_and_free(map, EXIT_FAILURE);
	map->image.player_down1 = mlx_xpm_file_to_image(map->minilibx,
			"Textures/down-1-40.xpm", &a, &a);
	if (!map->image.player_down1)
		exit_and_free(map, EXIT_FAILURE);
	map->image.player_left1 = mlx_xpm_file_to_image(map->minilibx,
			"Textures/left-1-40.xpm", &a, &a);
	if (!map->image.player_left1)
		exit_and_free(map, EXIT_FAILURE);
}

void	file_to_image(t_map *map)
{
	int	a;

	a = PIXELS;
	map->image.empty = mlx_xpm_file_to_image(map->minilibx,
			"Textures/empty.xpm", &a, &a);
	if (!map->image.empty)
		exit_and_free(map, EXIT_FAILURE);
	map->image.wall = mlx_xpm_file_to_image(map->minilibx,
			"Textures/wall.xpm", &a, &a);
	if (!map->image.wall)
		exit_and_free(map, EXIT_FAILURE);
	map->image.exit = mlx_xpm_file_to_image(map->minilibx,
			"Textures/door.xpm", &a, &a);
	if (!map->image.exit)
		exit_and_free(map, EXIT_FAILURE);
	map->image.collectible = mlx_xpm_file_to_image(map->minilibx,
			"Textures/Estrellita.xpm", &a, &a);
	if (!map->image.collectible)
		exit_and_free(map, EXIT_FAILURE);
	file_to_image_player(map);
}
