/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:14:17 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/08 14:59:02 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	image_to_window(t_info *info, char str, int x, int y)
{
	if (str == WALL)
		mlx_put_image_to_window(info->mlx, info->win, info->image[e_wall], x
			* 50, y * 50);
	else if (str == PATH)
		mlx_put_image_to_window(info->mlx, info->win, info->image[e_path], x
			* 50, y * 50);
	else if (str == PLAYER)
		mlx_put_image_to_window(info->mlx, info->win, info->image[e_player], x
			* 50, y * 50);
	else if (str == ITEM)
		mlx_put_image_to_window(info->mlx, info->win, info->image[e_item], x
			* 50, y * 50);
	else if (str == e_exit_close)
		mlx_put_image_to_window(info->mlx, info->win, info->image[e_exit_close],
			x * 50, y * 50);
	else if (str == e_exit_open)
		mlx_put_image_to_window(info->mlx, info->win, info->image[e_exit_open],
			x * 50, y * 50);
}

int	display_map(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i <= info->row)
	{
		j = 0;
		while (j <= info->col)
		{
			image_to_window(info, info->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (0);
}
