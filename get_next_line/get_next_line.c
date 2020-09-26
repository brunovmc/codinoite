/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcastanh <hcastanh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:38:31 by hcastanh          #+#    #+#             */
/*   Updated: 2020/09/25 22:40:37 by hcastanh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *s_line;
	char		*buffer;
	int			result;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	result = 1;
	*line = NULL;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!(s_line))
		s_line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (isbarran(s_line) == -1 && result >= 1 && result <= BUFFER_SIZE)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result >= 1 && result <= BUFFER_SIZE && s_line)
			s_line = ft_strjoin(s_line, buffer);
		ft_bzero(buffer);
	}
	if (result >= 0 && result <= BUFFER_SIZE)
		s_line = cleanline(line, s_line);
	free(buffer);
	if (result >= 1 && result <= BUFFER_SIZE)
		return (1);
	return (result == 0 ? 0 : -1);
}

char	*cleanline(char **line, char *s_line)
{
	char	*tmp;
	int		pos;

	pos = isbarran(s_line);
	if (pos >= 0)
	{
		s_line[pos] = '\0';
		*line = ft_calloc(pos + 1, sizeof(char));
		tmp = ft_calloc(ft_strlen(&s_line[pos + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, s_line, pos + 1);
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

int		isbarran(char *string)
{
	int i;

	if (!(string))
		return (-1);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
