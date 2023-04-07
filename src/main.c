/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:30:32 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/05 08:20:50 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*minilibx動作のテスト
int	my_key_hook(int key_code, void *data)
{
	printf("key_code=%d\n", key_code);
	(void)data;
	return (1);
}

int	my_destroy_hook(int key_code, void *data)
{
	printf("destroy=%d\n", key_code);
	(void)data;
	exit(EXIT_SUCCESS);
	return (1);
}
*/
static void	validate_mlx_error(t_info *info)
{
	if (info->mlx == NULL || info->win == NULL)
		free_map_and_exit(info, info->map, "Error\nMlx NULL");
}

int	main(int argc, char **argv)
{
	t_info	info;

	check_arg(argc, argv);
	set_loaded_map(&info, argv[1]);
	validate_map(&info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.col * 50 + 50, info.row * 50 + 50,
			"so_long");
	validate_mlx_error(&info);
	change_xpm_file_to_image(&info);
	display_map(&info);
	// setting_hook(&info);
	mlx_loop(info.mlx);
	// close_mlx(&info, loaded_map);
	return (0);
}
// マップ内容確認コード
// int		i = 0;
// printf("info->row = %d\n", info.row);
// printf("info->col = %d\n", info.col);
// while (i <= info.row)
// {
// 	ft_putstr_fd(loaded_map[i], 1);
// 	i++;
// }
/* minilibx動作テスト
	// int		width;
	// int		height;
	// void	*mlx;
	// void	*win;
	mlx = mlx_init();
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_get_screen_size(mlx, &width, &height);
	printf("width = %d\n", width);
	printf("height = %d\n", height);
	win = mlx_new_window(mlx, width / 3, height / 3, "so_longlong!!");
	mlx_hook(win, 17, 1, my_destroy_hook, NULL);
	// mlx_hook(win, 65307, 1, my_destroy_hook, NULL);
	mlx_key_hook(win, my_key_hook, NULL);
	mlx_loop(mlx);
	if (!win)
	{
		free(mlx);
		exit(EXIT_FAILURE);
	}
	free(mlx);
*/
