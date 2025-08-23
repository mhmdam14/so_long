/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:00:20 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/06 10:37:00 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end(t_map *map)
{
	write(1, "You surrendered!\n", 17);
	exit_and_free(map, EXIT_FAILURE);
	return (0);
}

void	win_msg(t_map *map)
{
	map->moves++;
	print_moves(map);
	write(1, "YOU WON!!!\n", 12);
	write(1, "Total Moves: ", 13);
	ft_putnbr_fd(map->moves, 1);
	write(1, "\n", 1);
	exit_and_free(map, EXIT_SUCCESS);
}
