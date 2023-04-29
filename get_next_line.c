/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:39:41 by mpoussie          #+#    #+#             */
/*   Updated: 2023/04/29 18:59:18 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


     
char	*gnt_read_line(int fd, char *left_str)
{
	char	*BUFFER;
	int		rd_bytes;

	BUFFER = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!BUFFER)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0 && !ft_strchr(left_str, '\n'))
	{
		rd_bytes = read(fd, BUFFER, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(BUFFER);
			return (NULL);
		}
		BUFFER[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, BUFFER);
	}
	free(BUFFER);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = gnt_read_line(fd, left_str);
	if (!left_str)
		return (NULL);
	line = gnt_get_line(left_str);
	return (left_str);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
