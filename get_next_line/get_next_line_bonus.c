/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharon-p <iharon-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 23:10:46 by iharon-p          #+#    #+#             */
/*   Updated: 2020/09/25 23:30:59 by iharon-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line_bonus(int fd, char **line)
{
	static char *s_line[OPEN_MAX];
	char		*buffer;
	int			result;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	result = 1;
	*line = NULL;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!(s_line[fd]))
		s_line[fd] = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (isbarran(s_line[fd]) == -1 && result >= 1 && result <= BUFFER_SIZE)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result >= 1 && result <= BUFFER_SIZE && s_line[fd])
			s_line[fd] = ft_strjoin(s_line[fd], buffer);
		ft_bzero(buffer);
	}
	if (result >= 0 && result <= BUFFER_SIZE)
		s_line[fd] = cleanline(line, s_line[fd]);
	free(buffer);
	if (result >= 1 && result <= BUFFER_SIZE)
		return (1);
	return (result == 0 ? 0 : -1);
}

char	*cleanline(char **line, char *s_line[fd])
{
	char	*tmp;
	int		pos;

	pos = isbarran(s_line[fd]);
	if (pos >= 0)
	{
		s_line[fd][pos] = '\0';
		*line = ft_calloc(pos + 1, sizeof(char));
		tmp = ft_calloc(ft_strlen(&s_line[fd][pos + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, s_line[fd], pos + 1);
		ft_strlcpy(tmp, &s_line[fd][pos + 1], ft_strlen(&s_line[fd][pos + 1]) + 1);
		free(s_line[fd]);
		s_line[fd] = NULL;
		return (tmp);
	}
	*line = (char*)ft_calloc(ft_strlen(s_line[fd]) + 1, sizeof(char));
	ft_strlcpy(*line, s_line[fd], ft_strlen(s_line[fd]) + 1);
	free(s_line[fd]);
	s_line[fd] = NULL;
	return (s_line[fd]);
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