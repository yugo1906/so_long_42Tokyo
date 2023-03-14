/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:30:32 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/15 08:47:08 by yughoshi         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**loaded_map;
	t_info	info;

	check_arg(argc, argv);
	loaded_map = get_read_map(&info, argv[1]);
	check_map(&info, loaded_map);

	/* minilibx動作テスト
	int		width;
	int		height;
	void	*mlx;
	void	*win;
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
	return (0);
}
