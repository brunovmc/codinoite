/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first-flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcastanh <hcastanh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:18:30 by hcastanh          #+#    #+#             */
/*   Updated: 2020/09/30 23:50:34 by hcastanh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int i;

	i = printf("8 letras");
	printf("\n%d\n", i);
	
	i = printf("8 %s", "letras");
	printf("\n%d\n", i);
	
	i = printf("13 caracteres");
	printf("\n%d\n", i);
	
	i = printf("%d %s", 13, "caracteres");
	printf("\n%d\n", i);
	
	i = printf("Uma frase com 27 caracteres");
	printf("\n%d\n", i);

	i = printf("Uma frase com %012d %s", 27 + 12 - 2, "caracteres");
	printf("\n%d\n", i);

	i = printf("Outra frase com 47 caracteres e um ponto final.");
	printf("\n%d\n", i);

	i = printf("Outra frase com %12d %s e um ponto final.", 47 + 12 - 2, "caracteres");
	printf("\n%d\n", i);

	i = printf("Eis aqui a última string, com seus 49 caracteres");
	printf("\n%d\n", i);

	i = printf("Eis aqui a última string, com seus %-12d %s", 49 + 12 - 2, "caracteres");
	printf("\n%d\n", i);
}
