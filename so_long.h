/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:45:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/29 22:48:47 by yughoshi         ###   ########.fr       */
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
# define COUNT_TYPE path

typedef struct s_game_data
{
	void	*mlx;
	void	*win;
	size_t	col;
	size_t	row;
	void	*image[COUNT_TYPE];
}			t_info;

typedef enum e_type
{
	player,
	wall,
	exit,
	item,
	path,
}			t_type;

void		check_arg(int argc, char **argv);
char		**get_loaded_map(t_info *info, char *file_name);
void		validate_map(t_info *info, char **loaded_map);
void		free_map(t_info *info, char **map);
void		free_map_and_exit(t_info *info, char **map, char *error_message);
void		free_two_map_exit(t_info *info, char **map, char **cp_map,
				char *ex_m);
void		free_copy_map(char **cp_map, size_t free_size);
void		validate_path(t_info *info, char **map);
#endif
