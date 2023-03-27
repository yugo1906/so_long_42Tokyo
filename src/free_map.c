/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:50:20 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/26 12:10:01 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_info *info, char **map)
{
	size_t	i;

	i = 0;
	while (i < info->row)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	free_map_and_exit(t_info *info, char **map, char *ex_m)
{
	free_map(info, map);
	ft_putstr_fd(ex_m, FD_2);
	exit(EXIT_FAILURE);
}

void	free_copy_map(char **cp_map, size_t free_size)
{
	size_t	i;

	i = 0;
	while (i <= free_size)
	{
		free(cp_map[i]);
		cp_map[i] = NULL;
		i++;
	}
	free(cp_map);
}