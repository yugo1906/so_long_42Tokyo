/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_xpm_file_to_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:05:37 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/08 14:28:10 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	create_image_ptr(t_info *info, t_type type, char *xpm_file)
{
	int	wid;
	int	hei;

	wid = 50;
	hei = 50;
	info->image[type] = mlx_xpm_file_to_image(info->mlx, xpm_file, &wid, &hei);
}

static void	create_image(t_info *info)
{
	create_image_ptr(info, e_player, "./img/player/player.xpm");
	create_image_ptr(info, e_wall, "./img/wall/wall.xpm");
	create_image_ptr(info, e_exit_close, "./img/exit/goal.xpm");
	create_image_ptr(info, e_exit_open, "./img/exit/goal.xpm");
	create_image_ptr(info, e_item, "./img/item/item.xpm");
	create_image_ptr(info, e_path, "./img/path/blue_path.xpm");
}

static void	validate_image(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < e_count_type)
	{
		if (info->image[i] == NULL)
			free_map_and_exit(info, info->map, "Error\nMlx NULL");
		i++;
	}
}

void	change_xpm_file_to_image(t_info *info)
{
	create_image(info);
	validate_image(info);
}
