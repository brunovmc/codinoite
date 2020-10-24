/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:04:30 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/23 21:55:30 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

