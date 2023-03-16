/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:10:47 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/16 09:38:31 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_gnl_strlen(const char *s);
size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_gnl_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_gnl_strjoin(char *s1, char const *s2);
char	*ft_gnl_strdup(const char *s1);

#endif
