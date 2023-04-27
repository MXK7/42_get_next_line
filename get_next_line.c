/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:39:41 by mpoussie          #+#    #+#             */
/*   Updated: 2023/04/27 19:23:06 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *gnt_left(int fd, char *left_str)
{
    char *BUFFER;
    int  rd_bytes;

    BUFFER = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!BUFFER)
        return(NULL);
    rd_bytes = 1;
    while (rd_bytes != 0 && !ft_strchr(left_str, '\n'))
    {
        rd_bytes = read(fd, BUFFER, BUFFER_SIZE);
        if (rd_bytes == -1)
        {
            free(BUFFER);
            return(NULL);
        }
        BUFFER[rd_bytes] = '\0';
        
    }
    
}

char *get_next_line(int fd)
{
    
}



int main() {
    FILE *f;
    char c;
    f=fopen("test.txt","rt");
    while((c=fgetc(f))!=EOF){
        printf("%c",c);
    }
    fclose(f);
    return 0;
}