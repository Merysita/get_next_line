#include "get_next_line.h"
//====================== R E S I Z E =======================
//Queremos que el stash, si no tiene un \n, se agrande y copie lo de buff.
//Hasta hallar un \n

//#########################################################################
//# AL BUFFER HAY QUE HACERLE UN MALLOC PARA PODER BORRAR Y VOLVER A LEER #
//#########################################################################

static char	*resize(char *stash, int fd)
{
	char	*buff;
	char	*tmp;
	size_t	len_buff;
	ssize_t	n_bytes;

	n_bytes = 1;
	buff = (char *) malloc((BUFF_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while ((ft_strchr(stash, '\n') == NULL) && n_bytes > 0)
	{
		n_bytes = read(fd, buff, BUFF_SIZE);
		if (n_bytes == -1)
			return(free(stash), free(buff), NULL);
		if (n_bytes == 0)
			break;
		buff[n_bytes] = '\0';
		if (!stash)
			stash = ft_strdup(buff);
		else
		{
			tmp = ft_strdup(stash);
			free(stash);
			len_buff = ft_strlen(buff);
			stash = ft_strjoin(tmp, buff, ft_strlen(tmp), len_buff);
			free(tmp);
			tmp = NULL;
		}
	}
	free(buff);
	buff = NULL;
	return (stash);
}

char *ft_free_stash(char **stash)
{
	char *ret;

	ret = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return(ret);
}

static char	*ft_extract_line(char **stash, char *ret)
{
	char	*tmp;
	size_t	len_ret;

	tmp = ft_strdup(&ft_strchr(*stash, '\n')[1]);
	if (!tmp)
		return (free(*stash), NULL);
	len_ret = ft_strlen(*stash) - ft_strlen(ft_strchr(*stash, '\n')) + 1;
	ret = ft_substr(*stash, 0, len_ret);
	free(*stash);
	*stash = ft_strdup(tmp);
	if (!*stash)
		return (free(ret), free(tmp), NULL);
	free(tmp);
	return (ret);
}

//Queremos que get next line cuando lo llamemos nos devuelva una frase

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*ret;

	ret = NULL;
	if (fd <= 0 || BUFF_SIZE < 1)
		return (NULL);
	stash = resize(stash, fd);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (ft_strchr(stash, '\n') != NULL)
	{
		ret = ft_extract_line(&stash, ret);
		return (ret);
	}
	return (ft_free_stash(&stash));
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char *line = NULL;
	int fd;
	int i;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		//write(1, line, strlen(line));
		printf("Main :%s", line);
		//write(1, "Z\n", 2);

		free(line);
		//printf("%s", line);

		
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
