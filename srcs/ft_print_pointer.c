/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:31:12 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/07 16:34:45 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putadd(long unsigned int nb, int *n, int print)
{
	int digit;

	if (nb == 0)
	{
		if (print)
			write(1, "0x0", 3);
		*n = 3;
		return ;
	}
	if (*n == 3 && print)
		write(1, "0x", 2);
	if (nb / 16 != 0)
	{
		*n = *n + 1;
		ft_putadd(nb / 16, n, print);
	}
	if (nb % 16 < 10)
		digit = nb % 16 + '0';
	else
		digit = nb % 16 + 'a' - 10;
	if (print)
		write(1, &digit, 1);
}

void	print_pointer(va_list args, t_arg arg, int *nbc)
{
	long unsigned int	nb;
	int					nb_digit;
	int					prec;

	nb_digit = 3;
	nb = (long unsigned int)va_arg(args, void*);
	ft_putadd(nb, &nb_digit, 0);
	nbc_ulint_up(nbc, arg, nb_digit, nb);
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
	nb_digit = 3;
	if (nb != 0 || arg.precision != 0)
		ft_putadd(nb, &nb_digit, 1);
	if (arg.flag == '-')
		print_chars(arg.field_width - prec, ' ');
}

void	nbc_uint_up(int *nbc, t_arg arg, int nb_digit, unsigned int nb)
{
	if (nb == 0 && arg.precision == 0)
		nb_digit = 0;
	if (arg.precision < nb_digit)
		arg.precision = nb_digit;
	if (arg.field_width < arg.precision)
		arg.field_width = arg.precision;
	*nbc = *nbc + arg.field_width;
}

void	nbc_ulint_up(int *nbc, t_arg arg, int nb_digit, long unsigned int nb)
{
	if (nb == 0 && arg.precision == 0)
	{
		*nbc = 0;
		return ;
	}
	if (arg.precision < nb_digit)
		arg.precision = nb_digit;
	if (arg.field_width < arg.precision)
		arg.field_width = arg.precision;
	*nbc = *nbc + arg.field_width;
}
