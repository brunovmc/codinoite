/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:13:48 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/01 00:37:46 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int 	i;
	char	c;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if ( str[i] == 'c')
			{
				c = va_arg(args, int);
				count += ft_putchar(c);
			}
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	int i;

	i = 0;
	i = printf("bbb%cbbbbbbbbbbbbb\n", 'A');
	printf("%d\n", i);
	i = 0;
	i = ft_printf("bbb%cbbbbbbbbbbbbb\n", 'A');
	printf("%d\n", i);

	return 0;
}
