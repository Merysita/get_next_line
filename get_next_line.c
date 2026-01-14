#include "get_next_line.h"

char	*custom_realloc(char *tmp, char buff[BUFF_SIZE])
{
	char	*keep_tmp;
	size_t	len_tmp;
	size_t	len_buff;

	len_tmp = ft_strlen(tmp);
	keep_tmp = (char *) malloc(len_tmp * sizeof(char));
	if (!keep_tmp)
		return (NULL);
	keep_tmp = ft_memcpy(keep_tmp, tmp, len_tmp);
	free(tmp);
	len_buff = ft_strlen(buff);
	tmp = (char *) malloc((len_tmp + len_buff) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp = ft_memcpy(tmp, keep_tmp, len_tmp);
	tmp = ft_memcpy(&tmp[len_tmp], buff, len_buff);
	return (tmp);
}

char	*free_tmp(char *tmp, char *line)
{
	char	*keep_tmp;
	size_t	len_keep_tmp;
	size_t	len_line;

	len_keep_tmp = ft_strlen(ft_strchr(tmp, '\n'));
	keep_tmp = (char *) malloc(len_keep_tmp * sizeof(char));
	if (!keep_tmp)
		return (NULL);
	keep_tmp = ft_memcpy(keep_tmp, ft_strchr(tmp, '\n'), len_keep_tmp);
	len_line = ft_strlen(tmp) - len_keep_tmp;
	line = (char *) malloc(len_line * sizeof(char));
	if (!line)
		return (NULL);
	line = ft_memcpy(line, tmp, len_line);
	free(tmp);
	tmp = (char *) malloc(len_keep_tmp * sizeof(char));
	if (!line)
		return (NULL);
	tmp = ft_memcpy(tmp, keep_tmp, len_keep_tmp);
	free(keep_tmp);
	return (line);
}

char	*get_next_line(int fd)
{
    char		buff[BUFF_SIZE];
    static char	*tmp;
	char		*line;

	tmp = NULL;
	line = NULL;
    if (fd <= 0)
        return (NULL);
	while (read(fd, buff, BUFF_SIZE) > 0 && !(fd <= 0))
	{
		if (tmp == NULL)
		{
			tmp = (char *) malloc(ft_strlen(buff) * sizeof(char));
			if (!tmp)
				return (NULL);
			tmp = ft_memcpy(tmp, buff, ft_strlen(buff));
		}
		else
			tmp = custom_realloc(tmp, buff);
		if (ft_strchr(tmp, '\n') != NULL)
			return (line = free_tmp(tmp, line));
	}
	return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char	*line = NULL;
	int		fd;
	char	buff[1024];
	ssize_t	read_bytes;

	fd = open("test.txt", O_RDONLY);

	read_bytes = read(fd, buff, 5);
	//line = get_next_line(fd);
	printf("%s", buff);
	read(fd, buff, 5);
	printf("%s", buff);
	free(line);
}