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
	char	*keep_stash;
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
		keep_stash = ft_strdup(stash);
		free(stash);
		len_buff = ft_strlen(buff);
		stash = ft_strjoin(keep_stash, buff, ft_strlen(keep_stash), len_buff);
		free(keep_stash);
		keep_stash = NULL;
	}
	free(buff);
	buff = NULL;
	/*if (ft_strchr(stash, '\n') != NULL)
		return (stash);*/
	return (stash);
}

static char	*ft_extract_line(char *stash, char *ret)
{
	char	*keep_stash;
	size_t	len_ret;

	keep_stash = ft_strdup(&ft_strchr(stash, '\n')[1]);
	if (!keep_stash)
		return (free(stash), NULL);
	len_ret = ft_strlen(stash) - ft_strlen(ft_strchr(stash, '\n')) + 1;
	ret = ft_substr(stash, 0, len_ret);
	free(stash);
	stash = ft_strdup(keep_stash);
	if (!stash)
		return (free(ret), free(keep_stash), NULL);
	free(keep_stash);
	return (ret);
}

static char	*ft_free_stash(char *stash)
{
	char	*ret;

	ret = ft_strdup(stash);
	free(stash);
	return(ret);
}

//Queremos que get next line cuando lo llamemos nos devuelva una frase

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*ret;

	ret = NULL;
	if (fd <= 0 || BUFF_SIZE < 1)
		return (NULL);
	if (!stash)
		stash = (char *) malloc(1 * sizeof(char));
	if (!stash)
		return (NULL);
	stash = resize(stash, fd);
	if (!stash)
		return (free(stash), NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (ft_strchr(stash, '\n') != NULL)
	{
		ret = ft_extract_line(stash, ret);
		return (ret);
	}
	return (ft_free_stash(stash));
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	//char	*line = NULL;
	int		fd;
	//char	buff[1024];
	//ssize_t	read_bytes;
	//int		i = 2;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	/*while (i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break ;
		free(line);
		i--;
	}
	close(fd);
	return (0);*/
}
