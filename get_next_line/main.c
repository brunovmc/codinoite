#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int			fd;
	int			retorno;
	char		*line;

	fd = open("./test1.txt", O_RDONLY);
	retorno = get_next_line(fd, &line);
	//printf("linha lida no main: %s\n", line);

	while(line)
	{
		printf("%s\n", line);
		free(line);
		if (retorno <= 0)
			break;
		retorno = get_next_line(fd, &line);
	}
	switch (retorno)
	{
		case -1:
			printf("Arquivo terminou com erro\n");
			break;
		case 0:
			printf("PROGRAMA TERMINOU DE MANEIRA CORRETA.\n");
			break;
		case 1:
			printf("Arquivo não foi lido por completo.\n");
			break;
	}
	close (fd);
	return (retorno);
}
