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

int get_next_line(int fd, char **line)
{
    static char *s_line;
    char        buffer;
    int         result;

    if (fd < 0 || BUFFER_SIZE < 1 || !(line))
        return (-1);
	result = 1;
	*line = NULL;
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!(s_line))
        s_line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    while (isbarran(s_line) == -1  && result >= 1 && result <= BUFFER_SIZE)
    {
        result = read(fd, buffer, BUFFER_SIZE);
        if (result >= 1 && result <= BUFFER_SIZE && s_line)
            s_line = ft_strjoin(s_line, buffer);
        bzero(buffer);
    }
    if (result >= 0 && result <= BUFFER_SIZE)
        s_line = cleanline(line, s_line);
	free(buffer);
    if (result >= 1 && result <= BUFFER_SIZE)
        return (1);
    return (result == 0 ? 0 : -1);
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
