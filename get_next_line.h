#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFF_SIZE
# define BUFF_SIZE 12
#endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);

#endif