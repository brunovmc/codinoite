/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcastanh <hcastanh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:13:53 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/02 23:45:21 by hcastanh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_flags {
	int		length;
	int		width;
	int		precision;
	int		minus;
	int		star;
	int		zero;
	char	format;
}				t_flags;

int		ft_printf(const char *str, ...);