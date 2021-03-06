/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:13:53 by hcastanh          #+#    #+#             */
/*   Updated: 2020/11/11 23:37:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PRECISION_EMPTY -1
# define PRECISION_TWIN -2

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
int 			ft_strlen(char *s);
int				ft_printf(const char *str, ...);
int				ft_printf_c(va_list args, t_flags *flags);
void			ft_printf_star(va_list args, t_flags *flags);
void			ft_init(t_flags *flags);
int				ft_isnum(int c);
int				ft_checkflags(const char *str, t_flags *flags);
int 			ft_printf_s(va_list args, t_flags *flags);

	int main(void);

#endif
