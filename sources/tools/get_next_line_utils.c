/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:46:39 by tgeorge           #+#    #+#             */
/*   Updated: 2023/11/28 07:45:59 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	const char	*ptr;

	if (!s)
		return (0);
	ptr = s;
	while ((unsigned char)*ptr != '\0'
		&& (unsigned char)*ptr != (unsigned char)c)
		ptr++;
	if ((unsigned char)*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (0);
}

char	*ft_fill_join(char *res, char *s1, char *s2)
{
	int	size1;
	int	size2;

	size1 = 0;
	size2 = 0;
	while (s1[size1])
	{
		res[size1] = s1[size1];
		size1++;
	}
	while (s2[size2])
	{
		res[size1 + size2] = s2[size2];
		size2++;
	}
	res[size1 + size2] = '\0';
	return (res);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		len;

	if (!s1)
	{
		s1 = ft_malloc(1 * sizeof(char), 0, 0, 0);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	res = ft_malloc(sizeof(char) * (len + 1), 0, 0, 0);
	if (!res)
		return (0);
	res = ft_fill_join(res, s1, s2);
	ft_malloc(0, 0, 1, s1);
	return (res);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size && (nmemb * size / size) != nmemb)
		return (0);
	ptr = ft_malloc(nmemb * size, 0, 0, 0);
	if (!ptr)
		return (0);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return ((unsigned char *)ptr);
}
