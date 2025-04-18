/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:41:23 by mcekici           #+#    #+#             */
/*   Updated: 2024/12/26 12:37:17 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int n, int *sum);
void	ft_put_un_nbr(unsigned int un, int *sum);
int		ft_hxdigit_count(unsigned long hex);
void	ft_putx_low(unsigned int hex, int *sum);
void	ft_putx_up(unsigned int hex, int *sum);
void	ft_putaddress(void *address, int *sum);
int		ft_printf(const char *format, ...);

#endif