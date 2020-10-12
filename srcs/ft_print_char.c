/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:12:10 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/12 15:27:42 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	nbc_char_up(int *nbc, t_arg arg)
{
	if (arg.field_width <= 0)
		arg.field_width = 1;
	*nbc = *nbc + arg.field_width;
}

void	print_char(va_list args, t_arg arg, int *nbc, int is_percent)
{
	unsigned char nb;

	if (is_percent)
		nb = '%';
	else
		nb = (unsigned char)va_arg(args, int);
	nbc_char_up(nbc, arg);
	if (arg.flag == '0')
		print_chars(arg.field_width - 1, '0');
	else if (arg.flag != '-')
		print_chars(arg.field_width - 1, ' ');
	write(1, &nb, 1);
	if (arg.flag == '-')
		print_chars(arg.field_width - 1, ' ');
}
