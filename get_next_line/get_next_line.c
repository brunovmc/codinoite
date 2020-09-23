#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    static char *s_line;
    char        *buffer;
    int         result;

    if (fd < 0 || BUFFER_SIZE < 1 || !line)
	    return (-1);
	result = 1;
	*line = NULL;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!(s_line))
        s_line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    while (isbarran(s_line) == -1  && result >= 1 && result <= BUFFER_SIZE)
    {
        result = read(fd, buffer, BUFFER_SIZE);
		// printf("Do GNL: linha lida: %s\n", buffer);
        if (result >= 1 && result <= BUFFER_SIZE && s_line)
		{
            s_line = ft_strjoin(s_line, buffer);
			// printf("Do GNL:linha lida: %s\n", s_line);
		}
        ft_bzero(buffer);
    }
    if (result >= 0 && result <= BUFFER_SIZE)
       s_line = cleanline(line, s_line);
	free(buffer);
	// printf("Do GNL:result: %s\n", s_line);
    if (result >= 1 && result <= BUFFER_SIZE)
        return (1);
    return (result == 0 ? 0 : -1);
}

char *cleanline(char **line, char *s_line)
{
    char    *tmp;
    int     pos;

    pos = isbarran(s_line);
    if (pos >= 0)
    {
        s_line[pos] = '\0';
        *line = ft_calloc(pos + 1, sizeof(char));
        tmp = ft_calloc(ft_strlen(&s_line[pos + 1]) + 1, sizeof(char));
        ft_strlcpy(*line, s_line, pos + 1); //adicionamos + 1 no pos por conta do indice
        ft_strlcpy(tmp, &s_line[pos + 1], ft_strlen(&s_line[pos + 1]) + 1);
        free(s_line);
        s_line = NULL;
        return (tmp);
    }
    *line = (char*)ft_calloc(ft_strlen(s_line) + 1, sizeof(char));
	ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
	free(s_line);
	s_line = NULL;
	return (s_line);
}

size_t    ft_strlcpy(char *dst, char *src, size_t dstsize)
{
    size_t    i;
    size_t    srclen;

    if (dst == 0 || src == 0)
        return (0);
    i = 0;
    srclen = ft_strlen(src);
    if (dstsize)
    {
        while (src[i] && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = 0;
    }
    return (srclen);
}

int isbarran(char *string)
{
    int i;

    if (!(string))
        return (-1);
    i = 0;
    while(string[i])
    {
        if (string[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)ft_calloc(i + j + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_calloc(size_t count, size_t size)
{
	char		*str;
	size_t		i;

	if (count > 1000000)
		count = 1000000;
	str = (char *)malloc(count * size);
	i = 0;
	if (str)
	{
		while (i < count)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}

void	ft_bzero(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (i < BUFFER_SIZE && i < 1000000)
		{
			str[i] = '\0';
			i++;
		}
	}
}
