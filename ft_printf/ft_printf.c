/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcastanh <hcastanh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:04:30 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/21 23:05:07 by hcastanh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_printf_star(va_list args, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->prec = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->prec = va_arg(args, int);
	}
}

int		ft_printf_c(va_list args, t_flags *flags)
{
	int		count;
	char	c;

	count = 0;
	ft_printf_star(args, flags);
	c = va_arg(args, int);
	if (flags->minus)
		count += ft_putchar(c);
	while (flags->width-- > 1)
		count += ft_putchar(' ');
	if (!flags->minus)
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



int		ft_isconversion(va_list args, t_flags *flags)
{
	int	count;
	count = 0;
	if (flags->conv == 'c')
		count += ft_printf_c(args, flags);
	// else if (flags->conv == 'd' || flags->conv == 'i')
	// 	count += ft_printf_d(args, flags);
	// else if (flags->conv == 's')
	// 	count += ft_printf_s(args, flags);
	return (count);
}

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

int		ft_isnum(int c)
{
	if (c >= 48 && c <=57)
		return (1);
	return (0);
}



int		ft_checkflags(const char *str, t_flags *flags)
{
	int		i;

	i = 0;
	while (str[i] == '-' || str[i] == '.' || str[i] == '*' ||
	ft_isnum(str[i]))
	{
		if (str[i] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		if (str[i] == '*')
		{
			if (flags->prec == -1) // se nao tiver um ponto ainda
				flags->star = 1; //flags->star relacionada ao width
			else
				flags->star = flags->star == 0 ? 2 : 3; // 2 para precisao  ---- 3 para largura e precisao
		}
		if (str[i] == '.')
			flags->prec = (flags->prec == PRECISION_EMPTY) ? 0 : PRECISION_TWIN;
		if (str[i] == '0' && !flags->minus && flags->width == 0)
			flags->zero = 1;
		if (ft_isnum(str[i]))
			while (ft_isnum(str[i]))
			{
				if (flags->prec == -1)
					flags->width = (flags->width * 10) + (str[i] - '0');
				if (flags->prec >= 0)
					flags->prec = (flags->prec * 10) + (str[i] - '0');
				i++;
			}
		else
			i++;
	}
	flags->conv = str[i];
	flags->len = i;
	return (i);
	//printf("%d", flags->len);
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
			i++;
			ft_init(&flags);
			ft_checkflags(&str[i], &flags);
			i += flags.len;
			count += ft_isconversion(args, &flags);
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

	printf("1|%-10c|\n", 'a');
	ft_printf("2|%-10c|\n", 'a');

	printf("3|%10c|\n", 'a');
	ft_printf("4|%10c|\n", 'a');

	printf("11|%*c|\n", 10, 'a');
	ft_printf("12|%*c|\n", 10, 'a');
	printf("13|%10.*c|\n", 5, 'a');
	ft_printf("14|%10.*c|\n", 5, 'a');
	printf("15|%*.*c|\n", 10, 5, 'a');
	ft_printf("16|%*.*c|\n", 10, 5, 'a');



	ft_printf("6|%*.*d|\n", 10, 5, 125);

	printf("7|%10.5d|\n", 125);

	ft_printf("8|%10c|\n", 'a');
	printf("9|%10.3f|\n", 125.0);

	return 0;
}
