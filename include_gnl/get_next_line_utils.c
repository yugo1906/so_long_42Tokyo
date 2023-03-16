/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:10:58 by yughoshi          #+#    #+#             */
/*   Updated: 2023/03/15 09:49:47 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*(s + length) != '\0')
	{
		length++;
	}
	return (length);
}

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (src[result])
		result++;
	if (dstsize == 0)
		return (result);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (result);
}

size_t	ft_gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (dstsize == 0)
		return (ft_gnl_strlen(src));
	dst_len = ft_gnl_strlen(dst);
	src_len = ft_gnl_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	if (dstsize > dst_len)
	{
		while (dst[i] != '\0')
			i++;
		dst = dst + i;
		i = 0;
		while (i < dstsize - dst_len - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst_len + src_len);
}

char	*ft_gnl_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1_len;

	s1_len = ft_gnl_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_gnl_strlcpy(ptr, s1, s1_len + 1);
	return (ptr);
}

char	*ft_gnl_strjoin(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_gnl_strdup(s2));
	if (s2 == NULL)
		return (ft_gnl_strdup(s1));
	len_s1 = ft_gnl_strlen(s1);
	len_s2 = ft_gnl_strlen(s2);
	res = (char *)malloc(len_s1 + len_s2 + 1);
	if (res == NULL)
		return (NULL);
	ft_gnl_strlcpy(res, s1, len_s1 + 1);
	ft_gnl_strlcat(res, s2, len_s1 + len_s2 + 1);
	free(s1);
	return (res);
}
