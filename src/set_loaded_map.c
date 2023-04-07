/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_loaded_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:51:00 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/08 05:25:30 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ex_handling_file_error(char *file_name)
{
	ft_putstr_fd("Error\n", FD_2);
	perror(file_name);
	exit(EXIT_FAILURE);
}

static void	ex_handling_malloc_error(void)
{
	ft_putstr_fd("Error\nmalloc failed\n", FD_2);
	exit(EXIT_FAILURE);
}

static void	ex_handling_gnl_error(char **loaded_map)
{
	size_t	i;

	i = 0;
	while (loaded_map[i] != NULL)
	{
		free(loaded_map[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}

static size_t	get_num_of_lines(t_info *info, char *file_name)
{
	int		fd;
	size_t	num_of_lines;
	char	*tmp;

	num_of_lines = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ex_handling_file_error(file_name);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		free(tmp);
		num_of_lines++;
	}
	info->row = num_of_lines - 1;
	close(fd);
	return (num_of_lines);
}

void	set_loaded_map(t_info *info, char *file_name)
{
	size_t	num_of_lines;
	int		fd;
	size_t	i;

	num_of_lines = get_num_of_lines(info, file_name);
	info->map = malloc(sizeof(char *) * (num_of_lines + 1));
	if (info->map == NULL)
		ex_handling_malloc_error();
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ex_handling_file_error(file_name);
	i = 0;
	while (i < num_of_lines)
	{
		info->map[i] = get_next_line(fd);
		if (info->map[i] == NULL)
			ex_handling_gnl_error(info->map);
		i++;
	}
	close(fd);
}
