/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:45:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/29 23:33:49 by yughoshi         ###   ########.fr       */
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
# define ROW 10
# define COL 20

typedef enum e_type
{
	so_long_player,
	so_long_wall,
	so_long_exit,
	so_long_item,
	so_long_path,
	count_type,
}			t_type;

typedef struct s_game_data
{
	void	*mlx;
	void	*win;
	size_t	col;
	size_t	row;
	char	*image[count_type];
}			t_info;

void		check_arg(int argc, char **argv);
char		**get_loaded_map(t_info *info, char *file_name);
void		validate_map(t_info *info, char **loaded_map);
void		free_map(t_info *info, char **map);
void		free_map_and_exit(t_info *info, char **map, char *error_message);
void		free_two_map_exit(t_info *info, char **map, char **cp_map,
				char *ex_m);
void		free_copy_map(char **cp_map, size_t free_size);
void		validate_path(t_info *info, char **map);
void		change_xpm_file_to_image(t_info *info, char **loaded_map);
#endif
