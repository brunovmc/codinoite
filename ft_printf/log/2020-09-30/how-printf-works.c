/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how-printf-works.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcastanh <hcastanh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:04:36 by hcastanh          #+#    #+#             */
/*   Updated: 2020/09/30 23:42:01 by hcastanh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int i;

	i = printf("8 letras");
	printf("\n%d\n", i);
	
	i = printf("13 caracteres");
	printf("\n%d\n", i);
	
	i = printf("Uma frase com 27 caracteres");
	printf("\n%d\n", i);

	i = printf("Outra frase com 47 caracteres e um ponto final.");
	printf("\n%d\n", i);

	i = printf("Eis aqui a última string, com seus 49 caracteres");
	printf("\n%d\n", i);
}