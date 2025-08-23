/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:56:11 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/11 11:29:52 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define PIXELS 50

typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

typedef struct s_image
{
	void	*empty;
	void	*exit;
	void	*collectible;
	void	*wall;
	void	*player_left1;
	void	*player_right1;
	void	*player_up1;
	void	*player_down1;
}	t_image;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**arr;
	char		**arr_copy;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			moves;
	void		*minilibx;
	void		*window;
	t_image		image;
	t_player	player;
}	t_map;

void	check_map(t_map *map);
void	map_array(t_map *map);
void	file_to_image(t_map *map);
void	print_map(t_map *map);
void	move_right(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
int		key_hook(int code, t_map *map);
int		end(t_map *map);
void	win_msg(t_map *map);
void	free_arr(char **arr, int i);
void	error_msg(void);
void	error_msg2(t_map *map);
void	exit_and_free(t_map *map, int code);
void	scan_player(t_map *map);
void	check_path(t_map *map);
void	print_moves(t_map *map);
void	free_both(char **a, char **b, int rows);

#endif