/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:39:43 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/01 15:23:12 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size;
	char	*dst;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	j = -1;
	size = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * size + 1);
	if (!dst)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	result;
	char	*ret;

	result = count * size;
	ret = malloc(result);
	if (!ret)
		return (NULL);
	ft_bzero(ret, result);
	return (ret);
}
