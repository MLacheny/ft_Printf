/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ints_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:03:49 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/05 19:23:52 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_int(t_arg arg, int nb, int *nb_digit, int print)
{
	if (arg.conv_spec == 'x')
		ft_putnbr_hex(nb, nb_digit, print, 'a');
	if (arg.conv_spec == 'X')
		ft_putnbr_hex(nb, nb_digit, print, 'A');
	if (arg.conv_spec == 'u')
		ft_putunbr(nb, nb_digit, print);
}

void	ft_putnbr_hex(unsigned int nb, int *n, int print, char c)
{
	int digit;

	if (nb / 16 != 0)
	{
		*n = *n + 1;
		ft_putnbr_hex(nb / 16, n, print, c);
	}
	if (nb % 16 < 10)
		digit = nb % 16 + '0';
	else
		digit = nb % 16 + c - 10;
	if (print)
		write(1, &digit, 1);
}

void	ft_putunbr(unsigned int nb, int *n, int print)
{
	int digit;

	if (nb / 10 != 0)
	{
		*n = *n + 1;
		ft_putunbr(nb / 10, n, print);
	}
	digit = nb % 10 + '0';
	if (print)
		write(1, &digit, 1);
}

void	print_u_int(va_list args, t_arg arg, int *nbc)
{
	unsigned int	nb;
	int				nb_digit;
	int				prec;

	nb = va_arg(args, unsigned int);
	nb_digit = init_unb_digit(nb, arg);
	put_int(arg, nb, &nb_digit, 0);
	nbc_uint_up(nbc, arg, nb_digit, nb);
	prec = arg.precision;
	if (prec < nb_digit)
		prec = nb_digit;
	if (arg.flag == '0')
		print_chars(arg.field_width - nb_digit, '0');
	else if (arg.flag != '-')
	{
		print_chars(arg.field_width - prec, ' ');
		print_chars(prec - nb_digit, '0');
	}
	else
		print_chars(prec - nb_digit, '0');
	nb_digit = init_unb_digit(nb, arg);
	if (nb != 0 || arg.precision != 0)
		put_int(arg, nb, &nb_digit, 1);
	if (arg.flag == '-')
		print_chars(arg.field_width - prec, ' ');
}

void	nbc_int_up(int *nbc, t_arg arg, int nb_digit, int nb)
{
	if (nb == 0 && arg.precision == 0)
		nb_digit = 0;
	if (arg.precision < nb_digit)
		arg.precision = nb_digit;
	if (arg.field_width < arg.precision)
		arg.field_width = arg.precision;
	*nbc = *nbc + arg.field_width;
}
