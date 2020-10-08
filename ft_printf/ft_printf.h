/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcastanh <hcastanh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:13:53 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/08 00:03:55 by hcastanh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>
# include <ctype.h>

typedef struct	s_flags {
	int		len;
	int		width;
	int		prec;
	int		star;
	int		minus;
	int		zero;
	char	conv;
}				t_flags;

int				ft_putchar(char c);
int				ft_printf(const char *str, ...);
int				ft_printf_c(va_list args);
void			ft_init(t_flags *flags);

#endif
