/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:36:17 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/12 15:29:27 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct	s_arg
{
	char	flag;
	int		field_width;
	int		precision;
	char	conv_spec;
}				t_arg;

unsigned int	init_unb_digit(int nb, t_arg arg);
void			print_chars(int nb, char c);
int				print_flags(int nb, int *nbc, t_arg arg, int nb_digit);
void			print_pointer(va_list args, t_arg arg, int *nbc);
void			ft_putunbr(unsigned int nb, int *n, int print);
void			print_u_int(va_list args, t_arg arg, int *nbc);
void			print_string(va_list args, t_arg arg, int *nbc);
void			print_char(va_list args, t_arg arg, int *nbc, int is_percent);
void			ft_putnbr_hex(unsigned int nb, int *n, int print, char c);
void			put_int(t_arg arg, int nb, int *nb_digit, int print);
void			ft_putnbr_rec(int nb, int *n, int print);
void			get_conv_spec(char **list, t_arg *arg);
void			get_precision(char **list, t_arg *arg, va_list args);
void			get_field_width(char **list, t_arg *arg, va_list args);
void			get_flag(char **list, t_arg *arg);
void			print_hexa_maj(va_list args, t_arg arg);
void			print_hexa(va_list args, t_arg arg);
void			print_int(va_list args, t_arg arg, int *nbc);
void			print_chars(int nb, char c);
void			ft_handle_underflow(int *n, int print);
void			ft_putnbr(int nb, int *n, int print);
void			print_arg(va_list list, t_arg arg, int *nbc);
int				is_arg(char c);
int				next_arg(char **list, t_arg *arg, va_list args, int *nbc);
void			get_prec(char **list, t_arg *arg);
void			arg_init(t_arg *arg);
void			nbc_int_up(int *nbc, t_arg arg, int nb_digit, int nb);
void			nbc_uint_up(int *nbc, t_arg arg, int nb_digit, unsigned int nb);
void			nbc_ulint_up(int *nbc, t_arg arg,
				int nb_digit, long unsigned int nb);
int				ft_printf(const char *list, ...);

#	endif
