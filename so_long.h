/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:45:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/05 08:29:27 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./include_gnl/get_next_line.h"
# include "./include_libft/libft.h"
# include "./include_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FD_2 2
# define PATH '0'
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define ITEM 'C'

typedef enum e_flag_row_or_col
{
	e_row,
	e_col,
}			t_flag_row_or_col;

typedef enum e_type
{
	e_player,
	e_wall,
	e_exit,
	e_item,
	e_path,
	count_type,
}			t_type;

typedef struct s_game_data
{
	void	*mlx;
	void	*win;
	size_t	col;
	size_t	row;
	size_t	item_num;
	size_t	player_num;
	size_t	exit_num;
	char	*image[count_type];
	size_t	player[2];
	char	**map;
}			t_info;

void		check_arg(int argc, char **argv);
char		**get_loaded_map(t_info *info, char *file_name);
void		validate_map(t_info *info);
void		free_map(t_info *info, char **map);
void		free_map_and_exit(t_info *info, char **map, char *error_message);
void		free_two_map_exit(t_info *info, char **map, char **cp_map,
				char *ex_m);
void		free_copy_map(char **cp_map, size_t free_size);
void		validate_path(t_info *info);
void		change_xpm_file_to_image(t_info *info);
void		display_map(t_info *info);
#endif
