/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:30:32 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/20 16:03:27 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_info	info;

	info.step_count = 0;
	check_arg(argc, argv);
	set_loaded_map(&info, argv[1]);
	validate_map(&info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.col * 50 + 50, info.row * 50 + 50,
			"so_long");
	validate_mlx_error(&info);
	change_xpm_file_to_image(&info);
	display_map(&info);
	setting_hook(&info);
	mlx_hook(info.win, ON_DESTROY, 1, my_mlx_close, &info);
	mlx_loop_hook(info.mlx, display_map, &info);
	mlx_loop(info.mlx);
	return (0);
}
