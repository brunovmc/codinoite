/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcastanh <hcastanh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:04:30 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/08 00:13:35 by hcastanh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_printf_c(va_list args)
{
	int		count;
	char	c;

	count = 0;

	c = va_arg(args, int);
	count += ft_putchar(c);
	return (count);
}

/*
** int		ft_printf_d()
** {
** 	int		count;
** 	char	d;
** 	count = 0;
** 
** }
** 
** int		ft_printf_s()
** {
** 	int		count;
** 	char	;
** 	count = 0;
** 
** }
*/



/*
** int		isconversion(va_list args)
** {
** 
** 
** 	int	count;
** 
** 	count = 0;
** 
** 	if (args == 'c')
** 	{
** 		count += ft_printf_c(args);
** 	}
** 	else if (args == 'd' || args == 'i')
** 	{
** 		count += ft_printf_d(args);
** 	}
** 	else if (args == 's')
** 	{
** 		count += ft_printf_s(args);
** 	}
** 
** 	return (count);
** }
*/

void	ft_init(t_flags *flags)
{
	flags->len = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->minus = 0;
	flags->star = 0;
	flags->zero = 0;
	flags->conv = '\0';
}

int		ft_checkflags(char *str, t_flags *flags)
{
	int		i;

	i = 0;
	while (str[i] == '-' || str[i] == '.' || str[i] == '*' ||
	isdigit(str[i]))
	{
		if (str[i] == '-')
			flags->minus = 1;
		if (str[i] == '*')
			flags->star = 1;
		if (str[i] == '.')
			flags->prec = 0;
		if (str[i] == '0' && !flags->minus)
			flags->zero = 0;
		if (isdigit(str[i]))
		{
			continue;
			//TODO;
		}
		i++;
	}
	return(i);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str); 
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_init(&flags);
			i++;
			if (str[i] == 'c')
				count += ft_printf_c(args);
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
	i = printf("bbb%10.0cbbbbbbbbbbbbb\n", 'A');
	printf("%d\n", i);

	i = 0;
	i = printf("bbb%10.cbbbbbbbbbbbbb\n", 'A');
	printf("%d\n", i);

	i = 0;
	i = printf("bbb%10cbbbbbbbbbbbbb\n", 'A');
	printf("%d\n", i);

	i = 0;
	i = printf("bbb%*cbbbbbbbbbbbbb\n", 10, 'A');
	printf("%d\n", i);

	i = 0;
	i = printf("bbb%-10cbbbbbbbbbbbbb\n", 'A');
	printf("%d\n", i);

	i = 0;
	i = ft_printf("bbb%cbbbbbbbbbbbbb\n", 'A');
	printf("%d\n", i);

	return 0;
}
