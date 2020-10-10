/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:04:30 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/10 01:04:39 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_printf_c(va_list args, t_flags *flags)
{
	int		count;
	char	c;

	count = 0;

	c = va_arg(args, int);
	/*
	if (flags->minus)
	{
		count += ft_putchar(c);
		while (flags->width-- > 1)
			count += ft_putchar(' ');
	}
	else
	{
		while (flags->width-- > 1)
			count += ft_putchar(' ');
		count += ft_putchar(c);
	}
	*/

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
			flags->star = 1;
			 /////// falta mexer nessa caralha vei
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
			if (str[i] == 'c')
				count += ft_printf_c(args, &flags);
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

	printf("|%-10c|\n", 'a');
	ft_printf("|%-10c|\n", 'a');

	printf("|%10c|\n", 'a');
	ft_printf("|%10c|\n", 'a');

	return 0;
}
