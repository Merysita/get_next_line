#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*pointer;

	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
	{
		pointer = (char *) &s[i];
		return (pointer);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s || len_s == 0)
	{
		start = 0;
		len = 0;
	}
	if (len > len_s - start)
		len = len_s - start;
	result = (char *) malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(char *src)
{
	char	*str;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!src)
	{
		str = (char *) malloc(sizeof(char) + 1);
		if (!str)
			return (free(src), NULL);
		str[0] = 0;
		return (str); 
	}
	size = ft_strlen(src) + 1;
	str = (char *) malloc(size * sizeof(char));
	if (!str)
		return (free(src), NULL);
	while (i < size - 1)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t l_s1, size_t l_s2)
{
	char	*result;
	size_t	len_join;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_join = l_s1 + l_s2 + 1;
	result = (char *) malloc(len_join * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < l_s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < l_s2 && s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
