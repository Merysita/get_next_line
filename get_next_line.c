#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char		buff[BUFF_SIZE];
    static char	*tmp;

	tmp = NULL;
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
		return (tmp);
	}
	return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char	*line = NULL;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
}