#include <unistd.h>

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
    char        buffer[BUFFER_SIZE + 1];
    int         result;

    if (fd < 0 || BUFFER_SIZE < 1 || !(line))
        return (-1);

    if (!(s_line))
        s_line = malloc(sizeof(char)BUFFER_SIZE + 1);

    while (isbarran(s_line) == -1)
    {
        result = read(fd, buffer, BUFFER_SIZE);
        if (result >= 1 && result <= BUFFER_SIZE)
            s_line = ft_strjoin(s_line, buffer);
        bzero(buffer);
    }
    if (result >= 0 && result <= BUFFER_SIZE)
        s_line = cleanline(line, s_line);
    if (result >= 1 && result <= BUFFER_SIZE)
        return (1);
    return (result == 0 ? 0 : -1);
}
