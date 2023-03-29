/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_xpm_file_to_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:05:37 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/29 23:24:35 by yughoshi         ###   ########.fr       */
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
	create_image_ptr(info, so_long_player, "img/player/ruffy.xpm");
	create_image_ptr(info, so_long_wall, "img/wall/hoge");
	create_image_ptr(info, so_long_exit, "img/exit/hoge");
	create_image_ptr(info, so_long_item, "img/item/hoge");
	create_image_ptr(info, so_long_path, "img/path/hoge");
}

static void	validate_image(t_info *info, char **loaded_map)
{
	size_t	i;

	i = 0;
	while (i < count_type)
	{
		if (info->image[i] == NULL)
			free_map_and_exit(info, loaded_map, "Error\nMlx NULL");
	}
}

void	change_xpm_file_to_image(t_info *info, char **loaded_map)
{
	create_image(info);
	validate_image(info, loaded_map);
}
