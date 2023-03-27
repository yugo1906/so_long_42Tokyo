/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:59:31 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/27 09:22:03 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**copy_map(t_info *info, char **map)
{
	char	**cp_map;
	size_t	i;
	size_t	j;

	cp_map = malloc(sizeof(char *) * (info->row + 1));
	if (cp_map == NULL)
		free_map_and_exit(info, map, "Error\nmalloc failed\n");
	i = 0;
	while (i <= info->row)
	{
		cp_map[i] = malloc(sizeof(char) * (info->col + 1));
		if (cp_map[i] == NULL)
		{
			free_copy_map(cp_map, i);
			free_map_and_exit(info, map, "Error\nmalloc failed\n");
		}
		j = 0;
		while (j <= info->col)
		{
			cp_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (cp_map);
}

static size_t	get_p_point(t_info *info, char **cp_map, size_t row_or_col)
{
	size_t	row_point;
	size_t	col_point;

	row_point = 1;
	while (row_point <= info->row)
	{
		col_point = 1;
		while (col_point <= info->col)
		{
			if (cp_map[row_point][col_point] == 'P' && row_or_col == ROW)
				return (row_point);
			if (cp_map[row_point][col_point] == 'P' && row_or_col == COL)
				return (col_point);
			col_point++;
		}
		row_point++;
	}
	return (0);
}

static void	set_mark(char **cp_map, size_t row, size_t col)
{
	if (cp_map[row][col] != '1' && cp_map[row][col] != 'M')
	{
		cp_map[row][col] = 'M';
		set_mark(cp_map, row, col + 1);
		set_mark(cp_map, row, col - 1);
		set_mark(cp_map, row + 1, col);
		set_mark(cp_map, row - 1, col);
	}
}

static void	validate_mark(t_info *info, char **cp_map, char **map, size_t i)
{
	size_t	j;
	size_t	is_all_items_collect;
	size_t	is_can_goal;

	is_all_items_collect = true;
	is_can_goal = false;
	while (i <= info->row)
	{
		j = 0;
		while (j <= info->col)
		{
			if (cp_map[i][j] == 'C' && map[i][j] == 'C')
				is_all_items_collect = false;
			else if (cp_map[i][j] == 'M' && map[i][j] == 'E')
				is_can_goal = true;
			j++;
		}
		i++;
	}
	if (is_all_items_collect && is_can_goal)
		return ;
	free_copy_map(cp_map, info->row);
	free_map_and_exit(info, map, "Error\nInvalid map\n");
}

void	validate_path(t_info *info, char **map)
{
	char	**cp_map;
	size_t	p_row_point;
	size_t	p_col_point;

	cp_map = copy_map(info, map);
	p_row_point = get_p_point(info, cp_map, ROW);
	p_col_point = get_p_point(info, cp_map, COL);
	set_mark(cp_map, p_row_point, p_col_point);
	validate_mark(info, cp_map, map, 0);
}
