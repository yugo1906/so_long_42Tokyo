/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:50:20 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/08 14:58:24 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_info *info, char **map)
{
	size_t	i;

	i = 0;
	while (i <= info->row)
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

void	free_map_and_exit_no_message(t_info *info, char **map)
{
	free_map(info, map);
	exit(EXIT_SUCCESS);
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
