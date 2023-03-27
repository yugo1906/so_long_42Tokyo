/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:46:17 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/26 12:52:31 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	validate_element(t_info *info, char **map, size_t i, size_t j)
{
	size_t	player_count;
	size_t	exit_count;
	size_t	item_count;

	player_count = 0;
	exit_count = 0;
	item_count = 0;
	while (++i <= info->row)
	{
		j = 0;
		while (j <= info->col)
		{
			if (!ft_strchr("01CEP", map[i][j]))
				free_map_and_exit(info, map, "Error\nForbidden elements\n");
			if (map[i][j] == 'P')
				player_count++;
			else if (map[i][j] == 'E')
				exit_count++;
			else if (map[i][j] == 'C')
				item_count++;
			j++;
		}
	}
	if (player_count != 1 || exit_count != 1 || item_count == 0)
		free_map_and_exit(info, map, "Error\nInvalid map\n");
}

static void	validate_rectangle(t_info *info, char **map)
{
	size_t	i;

	i = 0;
	info->col = ft_strlen(map[0]) - 2;
	while (i < info->row)
	{
		if (ft_strlen(map[i]) - 2 != info->col)
		{
			free_map_and_exit(info, map, "Error\nMap is not rectangle\n");
		}
		i++;
	}
	if (ft_strlen(map[i]) - 1 != info->col)
	{
		free_map_and_exit(info, map, "Error\nMap is not rectangle.\n");
	}
}

static void	validate_enclosed_wall(t_info *info, char **map)
{
	size_t	i;

	i = 0;
	while (i <= info->col)
	{
		if (map[0][i] != '1' || map[info->row][i] != '1')
			free_map_and_exit(info, map, "Error\nNot enclosed by walls\n");
		i++;
	}
	i = 0;
	while (i <= info->row)
	{
		if (map[i][info->col] != '1' || map[i][0] != '1')
			free_map_and_exit(info, map, "Error\nNot enclosed by walls\n");
		i++;
	}
}

void	validate_map(t_info *info, char **map)
{
	if (info->row == 0)
	{
		ft_putstr_fd("Error\nInvalid map\n", FD_2);
		exit(EXIT_FAILURE);
	}
	if (map[0][0] != '1')
	{
		ft_putstr_fd("Error\nThe first character in the file is not 1\n", FD_2);
		exit(EXIT_FAILURE);
	}
	validate_rectangle(info, map);
	validate_element(info, map, -1, 0);
	validate_enclosed_wall(info, map);
	validate_path(info, map);
}
