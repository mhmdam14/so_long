/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:27:10 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/11 11:27:40 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	error_msg2(t_map *map)
{
	int	count;

	count = 0;
	write(2, "Error\n", 6);
	if (map->arr)
	{
		while (map->arr[count])
			count++;
		free_arr(map->arr, count);
	}
	count = 0;
	if (map->arr_copy)
	{
		while (map->arr_copy[count])
			count++;
		free_arr(map->arr_copy, count);
	}
	if (map->file)
		free(map->file);
	exit(EXIT_FAILURE);
}
