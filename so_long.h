/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:45:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/15 08:39:50 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./include_gnl/get_next_line.h"
# include "./include_libft/libft.h"
# include "./include_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game_data
{
	void	*mlx;
	void	*win;
	size_t	col;
	size_t	row;
}			t_info;

void		check_arg(int argc, char **argv);
#endif
