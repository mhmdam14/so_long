/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:59:14 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 10:36:48 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	scan_player(t_map *map)
{
	map->player.y = 0;
	while (map->player.y < map->y)
	{
		map->player.x = 0;
		while (map->player.x < map->x)
		{
			if (map->arr[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->arr[map->player.y][map->player.x] == 'P')
			break ;
		map->player.y++;
	}
}

int	key_hook(int code, t_map *map)
{
	scan_player(map);
	if (code == ESC)
		return (end(map));
	else if (code == D)
		move_right(map);
	else if (code == W)
		move_up(map);
	else if (code == S)
		move_down(map);
	else if (code == A)
		move_left(map);
	return (0);
}
