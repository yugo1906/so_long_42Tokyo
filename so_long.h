/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:45:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/08 14:51:08 by yughoshi         ###   ########.fr       */
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
# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ON_DESTROY 17

typedef enum e_flag_row_or_col
{
	e_row,
	e_col,
}			t_flag_row_or_col;

typedef enum e_type
{
	e_player,
	e_wall,
	e_exit_close,
	e_exit_open,
	e_item,
	e_path,
	e_count_type,
}			t_type;

typedef struct s_game_data
{
	void	*mlx;
	void	*win;
	size_t	col;
	size_t	row;
	size_t	item_sum;
	size_t	player_sum;
	size_t	exit_sum;
	char	*image[6];
	size_t	player[2];
	char	**map;
	int		step_count;
}			t_info;

void		check_arg(int argc, char **argv);
void		set_loaded_map(t_info *info, char *file_name);
void		validate_map(t_info *info);
void		free_map(t_info *info, char **map);
void		free_map_and_exit(t_info *info, char **map, char *error_message);
void		free_two_map_exit(t_info *info, char **map, char **cp_map,
				char *ex_m);
void		free_copy_map(char **cp_map, size_t free_size);
void		free_map_and_exit_no_message(t_info *info, char **map);
void		validate_path(t_info *info);
void		change_xpm_file_to_image(t_info *info);
int			display_map(t_info *info);
void		setting_hook(t_info *info);
int			key_event(int keycode, t_info *info);
int			my_mlx_close(int key_code, t_info *info);
void		validate_mlx_error(t_info *info);

#endif
