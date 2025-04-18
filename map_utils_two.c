#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line/get_next_line_bonus.h"
#include "so_long.h"
#include <unistd.h>

static int		open_file(char *path);
static size_t	ft_strlen_modified(const char *s);
static void		copy_without_cr(char *dest, const char *src, size_t len1);
static char		*ft_strjoin_modified(char const *s1, char const *s2);

char	**get_map(char *path)
{
	int 	fd;
	char	**map;
	char	*map_buffer;
	char	*line;
	char	*temp;

	fd = open_file(path);
	temp = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_buffer = ft_strjoin_modified(temp, line);
		free(line);
		free(temp);
		if (!map_buffer)
			handle_error("Error\nMemory allocation failed.\n", 1, 0);
		temp = map_buffer;
	}
	close(fd);
	map = ft_split(map_buffer, '\n');
	if (!map)
		handle_error("Error\nMemory allocation failed.\n", 3, map_buffer);
	return (free(map_buffer), map);
}

static int	open_file(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFailed to open file.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static size_t	ft_strlen_modified(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != 0)
	{
		if (*s != '\r')
			len ++;
		s ++;
	}
	return (len);
}

static void	copy_without_cr(char *dest, const char *src, size_t len1)
{
	size_t	i;
    size_t	j;

    i = 0;
    j = 0;
    while (src[i])
    {
        if (src[i] != '\r')
            dest[len1 + j++] = src[i];
        i++;
    }
    dest[len1 + j] = '\0';
}

static char	*ft_strjoin_modified(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	len2 = ft_strlen_modified(s2);
	ptr = (char *)ft_calloc(1, len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	if (s1)
		ft_strlcpy(ptr, s1, len1 + 1);
	if (s2)
		copy_without_cr(ptr, s2, len1);
	return (ptr);
}
