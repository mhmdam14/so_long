/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:00:10 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/11 11:29:42 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr, int i)
{
	int	j;

	if (!arr)
		return ;
	j = 0;
	while (j < i)
	{
		if (arr[j])
			free(arr[j]);
		j++;
	}
	free(arr);
}

void	free_images(t_map *map)
{
	if (!map->minilibx)
		return ;
	if (map->image.empty)
		mlx_destroy_image(map->minilibx, map->image.empty);
	if (map->image.wall)
		mlx_destroy_image(map->minilibx, map->image.wall);
	if (map->image.exit)
		mlx_destroy_image(map->minilibx, map->image.exit);
	if (map->image.collectible)
		mlx_destroy_image(map->minilibx, map->image.collectible);
	if (map->image.player_left1)
		mlx_destroy_image(map->minilibx, map->image.player_left1);
	if (map->image.player_right1)
		mlx_destroy_image(map->minilibx, map->image.player_right1);
	if (map->image.player_up1)
		mlx_destroy_image(map->minilibx, map->image.player_up1);
	if (map->image.player_down1)
		mlx_destroy_image(map->minilibx, map->image.player_down1);
}

static void	free_arr_if(char **arr)
{
	int	count;

	count = 0;
	if (!arr)
		return ;
	while (arr[count])
		count++;
	free_arr(arr, count);
}

void	exit_and_free(t_map *map, int code)
{
	if (map->window && map->minilibx)
		mlx_destroy_window(map->minilibx, map->window);
	free_images(map);
	if (map->minilibx)
	{
		mlx_destroy_display(map->minilibx);
		free(map->minilibx);
	}
	free_arr_if(map->arr);
	free_arr_if(map->arr_copy);
	if (map->file)
		free(map->file);
	if (map->line)
		free(map->line);
	exit(code);
}

void	free_both(char **a, char **b, int rows)
{
	if (a)
		free_arr(a, rows);
	if (b)
		free_arr(b, rows);
}
