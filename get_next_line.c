/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mantunez <mantunez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:23:18 by mantunez          #+#    #+#             */
/*   Updated: 2026/02/11 12:51:42 by mantunez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_join_buff_stash(char *stash, char *buff)
{
	char	*tmp;
	size_t	len_buff;

	tmp = ft_strdup(stash);
	free(stash);
	len_buff = ft_strlen(buff);
	stash = ft_strjoin(tmp, buff, ft_strlen(tmp), len_buff);
	free(tmp);
	tmp = NULL;
	return (stash);
}

static char	*ft_resize(char *stash, int fd)
{
	char	*buff;
	ssize_t	n_bytes;

	n_bytes = 1;
	buff = (char *) malloc((BUFF_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while ((ft_strchr(stash, '\n') == NULL) && n_bytes > 0)
	{
		n_bytes = read(fd, buff, BUFF_SIZE);
		if (n_bytes == -1)
			return (free(stash), free(buff), NULL);
		if (n_bytes == 0)
			break ;
		buff[n_bytes] = '\0';
		if (!stash)
			stash = ft_strdup(buff);
		else
			stash = join_buff_stash(stash, buff);
	}
	free(buff);
	buff = NULL;
	return (stash);
}

char	*ft_free_stash(char **stash)
{
	char	*ret;

	ret = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (ret);
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

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*ret;

	ret = NULL;
	if (fd < 0 || BUFF_SIZE < 1)
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

/*#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char *line = NULL;
	int fd;

	//fd = open(stdin, O_RDONLY);
	line = get_next_line(0);
	while (line)
	{
		printf("Main :%s", line);

		free(line);
		
		line = get_next_line(0);
	}
	close(fd);
	return (0);
}*/
