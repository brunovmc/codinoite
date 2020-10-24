/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:44:47 by bvidigal          #+#    #+#             */
/*   Updated: 2020/10/23 21:44:47 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
