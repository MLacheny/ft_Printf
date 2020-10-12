/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:44:16 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/05 18:44:46 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_underflow(int *n, int print)
{
	*n = 11;
	if (print)
	{
		write(1, "2", 1);
		write(1, "1", 1);
		write(1, "4", 1);
		write(1, "7", 1);
		write(1, "4", 1);
		write(1, "8", 1);
		write(1, "3", 1);
		write(1, "6", 1);
		write(1, "4", 1);
		write(1, "8", 1);
	}
}

void	ft_putnbr(int nb, int *n, int print)
{
	if (nb == -2147483648)
	{
		ft_handle_underflow(n, print);
		return ;
	}
	else
		ft_putnbr_rec(nb, n, print);
}

void	ft_putnbr_rec(int nb, int *n, int print)
{
	int	digit;

	if (nb < 0)
	{
		nb *= -1;
		*n = *n + 1;
	}
	if (nb / 10 != 0)
	{
		*n = *n + 1;
		ft_putnbr_rec(nb / 10, n, print);
	}
	digit = nb % 10 + '0';
	if (print)
		write(1, &digit, 1);
}

void	print_chars(int nb, char c)
{
	while (nb-- > 0)
		write(1, &c, 1);
}

void	print_int(va_list args, t_arg arg, int *nbc)
{
	int nb;
	int	nb_digit;
	int prec;

	nb_digit = 1;
	nb = va_arg(args, int);
	if (nb == 0 && arg.precision == 0)
		nb_digit = 0;
	ft_putnbr(nb, &nb_digit, 0);
	nbc_int_up(nbc, arg, nb_digit, nb);
	prec = print_flags(nb, nbc, arg, nb_digit);
	nb_digit = 1;
	if (nb == 0 && arg.precision == 0)
		nb_digit = 0;
	if (nb != 0 || arg.precision != 0)
		ft_putnbr(nb, &nb_digit, 1);
	if (arg.flag == '-')
		print_chars(arg.field_width - prec, ' ');
}
