#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
	char	*line = NULL;
	int		fd;
	char	*buff;
    int size = 10;

	fd = open("test.txt", O_RDONLY);
    
	buff = (char *) malloc(size * sizeof(char));

    read(fd, buff, size);
	printf("%s\n", buff);

	free(buff);

    read(fd, buff, size);
    printf("%s%zu\n", buff, ft_strlen(buff));


	//printf("%s", ft_strjoin("Hola", "cara", 4, 4));
}