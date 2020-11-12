/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:54:18 by bvidigal          #+#    #+#             */
/*   Updated: 2020/10/23 21:54:18 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printf_star(va_list args, t_flags *flags)
{
    if (flags->star == 1) //igual a largura
        flags->width = va_arg(args, int);
    else if (flags->star == 2) //igual a precisao
        flags->prec = va_arg(args, int);
    else if (flags->star == 3)
    {
        flags->width = va_arg(args, int);
        flags->prec = va_arg(args, int);
    }
}

void ft_init(t_flags *flags)
{
    flags->len = 0;
    flags->width = 0;
    flags->prec = -1;
    flags->minus = 0;
    flags->star = 0;
    flags->zero = 0;
    flags->conv = '\0';
}

int ft_checkflags(const char *str, t_flags *flags)
{
    int i;

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
                flags->star = 1;   //flags->star relacionada ao width
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
}