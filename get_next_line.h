#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFF_SIZE
# define BUFF_SIZE 2
#endif

#ifndef FD_SIZE
# define FD_SIZE 1
#endif

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2, size_t l_s1, size_t l_s2);

#endif