/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:29:42 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/23 08:15:47 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_arg(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nfile name required\n", FD_2);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (len <= 4)
	{
		ft_putstr_fd("Error\nFile name is 4 characters or less\n", FD_2);
		exit(EXIT_FAILURE);
	}
	if (ft_memcmp(&argv[1][len - 4], ".ber", 5))
	{
		ft_putstr_fd("Error\nFile isn`t the .ber extension\n", FD_2);
		exit(EXIT_FAILURE);
	}
}
