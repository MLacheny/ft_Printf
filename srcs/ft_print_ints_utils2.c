/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ints_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:38:02 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/05 19:14:00 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				print_flags(int nb, int *nbc, t_arg arg, int nb_digit)
{
	if (arg.flag != '0' && arg.flag != '-')
		arg.flag = ' ';
	if (nb < 0)
	{
		if (arg.precision >= arg.field_width && arg.precision >= nb_digit)
		{
			*nbc = *nbc + 1;
		}
		arg.precision++;
	}
	if (arg.precision < nb_digit)
		arg.precision = nb_digit;
	if (arg.flag == '0' && nb < 0)
		write(1, "-", 1);
	if (arg.flag != '-')
		print_chars(arg.field_width - arg.precision, arg.flag);
	if (nb < 0 && arg.flag != '0')
		write(1, "-", 1);
	print_chars(arg.precision - nb_digit, '0');
	return (arg.precision);
}

unsigned int	init_unb_digit(int nb, t_arg arg)
{
	if (nb == 0 && arg.precision == 0)
		return (0);
	return (1);
}
