#include "get_next_line.h"

//Tenemos que redimensionar stash hasta que contenga un \n o \0
char	*resize(char *stash, char buff[BUFF_SIZE])
{
	char	*keep_stash;
	size_t	len_stash;
	size_t	len_buff;

	while (ft_strchr(stash, '\n') == NULL || ft_strchr(stash, '\0') == NULL)
	{
		len_stash = ft_strlen(stash);
		keep_stash = (char *) malloc(len_stash * sizeof(char));
		if (!keep_stash)
			return (free(stash), NULL);
		keep_stash = ft_memcpy(keep_stash, stash, len_stash);
		free(stash);
		len_buff = ft_strlen(buff);
		stash = (char *) malloc((len_stash + len_buff) * sizeof(char));
		if (!stash)
			return (NULL);
		stash = ft_memcpy(stash, keep_stash, len_stash);
		stash = ft_memcpy(&stash[len_stash], buff, len_buff);
	}
	return (stash);
}

char	*free_stash(char *stash, char *line)
{
	char	*keep_stash;
	size_t	len_keep_stash;
	size_t	len_line;

	len_keep_stash = ft_strlen(ft_strchr(stash, '\n'));
	keep_stash = (char *) malloc(len_keep_stash * sizeof(char));
	if (!keep_stash)
		return (NULL);
	keep_stash = ft_memcpy(keep_stash, ft_strchr(stash, '\n'), len_keep_stash);
	len_line = ft_strlen(stash) - len_keep_stash;
	line = (char *) malloc(len_line * sizeof(char));
	if (!line)
		return (NULL);
	line = ft_memcpy(line, stash, len_line);
	free(stash);
	stash = (char *) malloc(len_keep_stash * sizeof(char));
	if (!line)
		return (NULL);
	stash = ft_memcpy(stash, keep_stash, len_keep_stash);
	free(keep_stash);
	return (line);
}

//Queremos que get next line cuando lo llamemos nos devuelva una frase

char	*get_next_line(int fd)
{
	char		buff[BUFF_SIZE];
	static char	*stash[FD_SIZE];
	char		*line;

	line = NULL;
	if (read(fd, buff, BUFF_SIZE) < 0 && fd <= 0)
		return (NULL);
	if (!stash[fd])
		stash = (char *) malloc(1 * sizeof(char));
	if (!stash)
		return (NULL);
	stash = resize(stash, buff);
	if ()
		return (free(stash), NULL);
	if (ft_strchr(stash, '\n') != NULL)
		return (line = free_stash(stash, line));
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