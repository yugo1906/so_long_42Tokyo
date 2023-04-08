/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:46:17 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/08 07:21:39 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_element(t_info *info, size_t i, size_t j)
{
	if (!ft_strchr("01CEP", info->map[i][j]))
		free_map_and_exit(info, info->map, "Error\nForbidden elements\n");
	if (info->map[i][j] == PLAYER)
	{
		info->player_sum++;
		info->player[e_row] = i;
		info->player[e_col] = j;
	}
	else if (info->map[i][j] == EXIT)
	{
		info->exit_sum++;
		info->map[i][j] = e_exit_close;
	}
	else if (info->map[i][j] == ITEM)
		info->item_sum++;
}

static void	validate_element(t_info *info, size_t i, size_t j)
{
	info->player_sum = 0;
	info->exit_sum = 0;
	info->item_sum = 0;
	while (i <= info->row)
	{
		j = 0;
		while (j <= info->col)
		{
			check_element(info, i, j);
			j++;
		}
		i++;
	}
	if (info->player_sum != 1 || info->exit_sum != 1 || info->item_sum == 0)
		free_map_and_exit(info, info->map, "Error\nInvalid map\n");
}

static void	validate_rectangle(t_info *info)
{
	size_t	i;

	i = 0;
	info->col = ft_strlen(info->map[0]) - 2;
	while (i < info->row)
	{
		if (ft_strlen(info->map[i]) - 2 != info->col)
		{
			free_map_and_exit(info, info->map, "Error\nMap is not rectangle\n");
		}
		i++;
	}
	if (ft_strlen(info->map[i]) - 1 != info->col)
	{
		free_map_and_exit(info, info->map, "Error\nMap is not rectangle.\n");
	}
}

static void	validate_enclosed_wall(t_info *info)
{
	size_t	i;

	i = 0;
	while (i <= info->col)
	{
		if (info->map[0][i] != WALL || info->map[info->row][i] != WALL)
			free_map_and_exit(info, info->map, "Error\nNot walls enclosed\n");
		i++;
	}
	i = 0;
	while (i <= info->row)
	{
		if (info->map[i][info->col] != WALL || info->map[i][0] != WALL)
			free_map_and_exit(info, info->map, "Error\nNot walls enclosed\n");
		i++;
	}
}

void	validate_map(t_info *info)
{
	if (info->row == 0)
	{
		ft_putstr_fd("Error\nInvalid map\n", FD_2);
		exit(EXIT_FAILURE);
	}
	if (info->map[0][0] != WALL)
	{
		ft_putstr_fd("Error\nThe first character in the file is not 1\n", FD_2);
		exit(EXIT_FAILURE);
	}
	validate_rectangle(info);
	validate_element(info, 0, 0);
	validate_enclosed_wall(info);
	validate_path(info);
}
