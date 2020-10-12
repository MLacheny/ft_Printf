/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:35:48 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/07 16:51:08 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_null(int i)
{
	if (i == 0)
		write(1, "(", 1);
	if (i == 1)
		write(1, "n", 1);
	if (i == 2)
		write(1, "u", 1);
	if (i == 3 || i == 4)
		write(1, "l", 1);
	if (i == 5)
		write(1, ")", 1);
}

void	ft_putstr(char *str, int prec)
{
	int i;

	i = 0;
	if (!str)
	{
		while (i < prec && i < 6)
			print_null(i++);
	}
	else
	{
		while (str[i] && i < prec)
		{
			write(1, str + i, 1);
			i++;
		}
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	nbc_str_up(int *nbc, t_arg arg, int nb_digits)
{
	if (arg.precision == -1)
		arg.precision = nb_digits;
	if (nb_digits > arg.precision)
		nb_digits = arg.precision;
	if (nb_digits > arg.field_width)
		arg.field_width = nb_digits;
	*nbc = *nbc + arg.field_width;
}

void	print_string(va_list args, t_arg arg, int *nbc)
{
	char	*str;
	int		size;

	str = va_arg(args, char*);
	if (!str)
		size = 6;
	else
		size = ft_strlen(str);
	nbc_str_up(nbc, arg, size);
	if (arg.precision > size || arg.precision == -1)
		arg.precision = size;
	if (arg.flag == '0')
		print_chars(arg.field_width - arg.precision, '0');
	else if (arg.flag != '-')
		print_chars(arg.field_width - arg.precision, ' ');
	ft_putstr(str, arg.precision);
	if (arg.flag == '-')
		print_chars(arg.field_width - arg.precision, ' ');
}
