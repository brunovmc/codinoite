/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 22:18:27 by bvidigal          #+#    #+#             */
/*   Updated: 2020/10/23 22:18:27 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf_s(va_list args, t_flags *flags)
{
    int     count;
    char    *str;
    int     len;
    //int     point;

    ft_printf_star(args, flags);
    str = va_arg(args, char *);
    count = 0;
    if (str == NULL)
        str = "(null)";
    len = ft_strlen(str);
    //point = flags->prec > len ? len : flags->prec;
    if (flags->len == 0 || (flags->prec == -1 && len >= flags->width))
        while (*str)
            count += ft_putchar(*str++);
    return (count);
}
