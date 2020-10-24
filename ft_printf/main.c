/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:44:56 by bvidigal          #+#    #+#             */
/*   Updated: 2020/10/23 21:44:56 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    ft_printf("\n-----------------------------\n");
    ft_printf("\n--------conversion c---------\n");
    ft_printf("\n-----------------------------\n");
    printf("00teste%cteste\n", 'X');
    printf("01teste%-cteste\n", 'X');
    printf("02teste%5cteste\n", 'X');
    printf("03teste%cteste\n", 'X');
    ft_printf("---------------------------\n");
    ft_printf("00teste%cteste\n", 'X');
    ft_printf("01teste%-cteste\n", 'X');
    ft_printf("02teste%5cteste\n", 'X');
    ft_printf("03teste%cteste\n", 'X');
    printf("\n-----------------------------\n");
    printf("\n--------conversion s---------\n");
    printf("\n-----------------------------\n");
    // printf("01%s\n", "teste");
    // printf("02%-s\n", "teste");
    // printf("03%4sG\n", "teste");
    // printf("04%7sG\n", "teste");
    // printf("05%8.0sG\n", "teste");
    // printf("06%8.3sG\n", "teste");
    // printf("07%-8.0sG\n", "teste");
    // printf("08%-8.3sG\n", "teste");
    // printf("09%-8.sG\n", "teste");
    // printf("10%8sG\n", "teste");
    // printf("11%4.5sG\n", "teste");
    // printf("12%4.4sG\n", "teste");
    // printf("13%4.7sG\n", "teste");
    // printf("14%8.7sG\n", "teste");
    // printf("15%-8.7sG\n", "teste");
    // printf("16%-.7sG\n", "teste");
    // printf("17%8.5sG\n", "teste");
    // printf("18|%4.15s|\n", "42");
    // printf("19|%4.15s|\n", NULL);
    ft_printf("---------------------------\n");
    // ft_printf("01%s\n", "teste");
    // ft_printf("02%-s\n", "teste");
    // ft_printf("03%4sG\n", "teste");
    // ft_printf("04%7sG\n", "teste");
    // ft_printf("05%8.0sG\n", "teste");
    // ft_printf("06%8.3sG\n", "teste");
    // ft_printf("07%-8.0sG\n", "teste");
    // ft_printf("08%-8.3sG\n", "teste");
    // ft_printf("09%-8.sG\n", "teste");
    // ft_printf("10%8sG\n", "teste");
    // ft_printf("11%4.5sG\n", "teste");
    // ft_printf("12%4.4sG\n", "teste");
    // ft_printf("13%4.7sG\n", "teste");
    // ft_printf("14%8.7sG\n", "teste");
    // ft_printf("15%-8.7sG\n", "teste");
    // ft_printf("16%-.7sG\n", "teste");
    // ft_printf("17%8.5sG\n", "teste");
    // ft_printf("18|%4.15s|\n", "42");
    // ft_printf("19|%4.15s|\n", NULL);
    return 0;
}