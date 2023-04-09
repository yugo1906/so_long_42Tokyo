/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:02:26 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/08 14:52:09 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	change_exit_to_open(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i <= info->row)
	{
		j = 0;
		while (j <= info->col)
		{
			if (info->map[i][j] == e_exit_close)
				info->map[i][j] = e_exit_open;
			j++;
		}
		i++;
	}
}

void	move_player(t_info *info, size_t x, size_t y)
{
	if (info->map[x][y] == ITEM)
	{
		info->item_sum--;
		if (info->item_sum == 0)
			change_exit_to_open(info);
	}
	if (info->map[x][y] != WALL && info->map[x][y] != e_exit_close)
	{
		info->map[info->player[e_row]][info->player[e_col]] = PATH;
		info->player[e_row] = x;
		info->player[e_col] = y;
		info->step_count++;
		ft_printf("step : %d\n", info->step_count);
		if (info->map[x][y] == e_exit_open)
		{
			ft_printf("Congratulation! Game Clear!\n");
			free_map_and_exit_no_message(info, info->map);
		}
		info->map[info->player[e_row]][info->player[e_col]] = PLAYER;
		display_map(info);
	}
}

int	key_event(int keycode, t_info *info)
{
	size_t	x;
	size_t	y;

	x = info->player[e_row];
	y = info->player[e_col];
	if (keycode == KEY_A)
		move_player(info, x, y - 1);
	if (keycode == KEY_D)
		move_player(info, x, y + 1);
	if (keycode == KEY_W)
		move_player(info, x - 1, y);
	if (keycode == KEY_S)
		move_player(info, x + 1, y);
	if (keycode == KEY_ESC || keycode == KEY_Q || keycode == ON_DESTROY)
		free_map_and_exit_no_message(info, info->map);
	return (0);
}

void	setting_hook(t_info *info)
{
	mlx_key_hook(info->win, key_event, info);
}
