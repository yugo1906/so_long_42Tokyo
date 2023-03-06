/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:30:32 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/07 00:46:38 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	my_key_hook(int key_code, void *data)
{
	printf("key_code=%d\n", key_code);
	(void)data;
	return (1);
}

int	my_destroy_hook(int key_code, void *data)
{
	printf("destroy\n");
	exit(EXIT_SUCCESS);
	return (1);
}

int	main(void)
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	// nullが帰ってきた時の処理が必要
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_get_screen_size(mlx, &width, &height);
	printf("width = %d\n", width);
	printf("height = %d\n", height);
	win = mlx_new_window(mlx, width / 3, height / 3, "yughoshi");
	mlx_hook(win, 17, 1, my_destroy_hook, NULL);
	mlx_key_hook(win, my_key_hook, NULL);
	mlx_loop(mlx);
	if (!win)
	{
		free(mlx);
		exit(EXIT_FAILURE);
	}
	free(mlx);
	return (0);
}

// mlx_init
// mlx windowに接続するための関数
