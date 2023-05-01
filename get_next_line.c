/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:39:41 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/01 03:58:13 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnt_next(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] != '\n' && left_str[i])
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(left_str) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	free(left_str);
	return (str);
}

char	*gnt_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] && left_str[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	gnt_free(char *left_str, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(left_str, buffer);
	free(buffer);
	return (tmp)
}

char	*gnt_read(int fd, char *left_str)
{
	char	*buffer;
	int		rd_bytes;

	if (!left_str)
		buffer = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd_bytes] = 0;
		left_str = gnt_free(left_str, buffer);
		if (ft_strchr(left_str,'\n')) 
		break ;
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	left_str = gnt_read(fd, left_str);
	if (!left_str)
		return (NULL);
	line = gnt_line(left_str);
	left_str = gnt_next(left_str);
	return (line);
}
