/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:29:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/08 14:57:08 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	my_mlx_close(int key_code, t_info *info)
{
	(void)key_code;
	(void)info;
	exit(EXIT_SUCCESS);
}

void	validate_mlx_error(t_info *info)
{
	if (info->mlx == NULL || info->win == NULL)
		free_map_and_exit(info, info->map, "Error\nMlx NULL");
}
