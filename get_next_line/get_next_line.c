/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:02:46 by mcekici           #+#    #+#             */
/*   Updated: 2024/12/24 13:02:46 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_get_line(char *str)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	if (!(*str))
		return (NULL);
	while (str[len] && str[len] != '\n')
		len ++;
	if (str[len] == '\n')
		len ++;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (free(str), NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = str[i];
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_get_after_line(char	*str)
{
	char	*ptr;
	char	*iter_str;
	char	*iter_ptr;

	iter_str = str;
	while (*iter_str && *iter_str != '\n')
		iter_str ++;
	if (*iter_str == '\0')
		return (free(str), NULL);
	if (*iter_str == '\n')
		iter_str ++;
	ptr = (char *)malloc(ft_strlen(iter_str) + 1);
	if (!ptr)
		return (free(str), NULL);
	iter_ptr = ptr;
	while (*iter_str)
		*(iter_ptr++) = *(iter_str++);
	*iter_ptr = '\0';
	free(str);
	return (ptr);
}

static char	*ft_read_func(char *str, int fd)
{
	int		byte_readed;
	char	*buffer;

	byte_readed = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && byte_readed != 0)
	{
		byte_readed = read(fd, buffer, BUFFER_SIZE);
		if (byte_readed == -1 || (!byte_readed && !str))
			return (free(str), free(buffer), NULL);
		buffer[byte_readed] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_read_func(str, fd);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_get_after_line(str);
	return (line);
}
