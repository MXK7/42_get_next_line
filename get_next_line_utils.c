/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:39:43 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/01 03:34:52 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*new_str;

	new_str = (char *)str;
	while (*new_str != c && *new_str != 0)
		new_str++;
	if (*new_str == c)
		return (new_str);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!s1 || !s2 || !str)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[i] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[size] = 0;
	return (str);
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
