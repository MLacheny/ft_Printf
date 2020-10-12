/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:46:55 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/12 15:29:06 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_flag(char **list, t_arg *arg)
{
	while (*(++(*list)) == '0' || **list == '-')
	{
		if (**list == '0' && arg->flag != '-')
			arg->flag = '0';
		if (**list == '-')
			arg->flag = '-';
	}
}

void	get_field_width(char **list, t_arg *arg, va_list args)
{
	if (**list == '*')
	{
		arg->field_width = va_arg(args, int);
		if (arg->field_width < 0)
		{
			arg->flag = '-';
			arg->field_width = arg->field_width * -1;
		}
		*list = *list + 1;
		return ;
	}
	while (**list >= '0' && **list <= '9')
		arg->field_width = arg->field_width * 10 + *((*list)++) - '0';
}

int		next_arg(char **list, t_arg *arg, va_list args, int *nbc)
{
	while (**list)
	{
		if (**list == '%')
		{
			get_flag(list, arg);
			get_field_width(list, arg, args);
			get_precision(list, arg, args);
			get_conv_spec(list, arg);
			if (arg->precision != -1 && arg->flag == '0')
				arg->flag = 1;
			return (1);
		}
		else
		{
			write(1, (*list)++, 1);
			*nbc = *nbc + 1;
		}
	}
	return (0);
}

void	print_arg(va_list args, t_arg arg, int *nbc)
{
	if (arg.conv_spec == 'd' || arg.conv_spec == 'i')
		print_int(args, arg, nbc);
	else if (arg.conv_spec == 'x' || arg.conv_spec == 'X'
		|| arg.conv_spec == 'u')
		print_u_int(args, arg, nbc);
	else if (arg.conv_spec == 'c')
		print_char(args, arg, nbc, 0);
	else if (arg.conv_spec == 's')
		print_string(args, arg, nbc);
	else if (arg.conv_spec == 'p')
		print_pointer(args, arg, nbc);
	else if (arg.conv_spec == '%')
		print_char(args, arg, nbc, 1);
}

int		ft_printf(const char *list, ...)
{
	va_list	args;
	char	**list_cp;
	t_arg	arg;
	int		nbc;

	nbc = 0;
	if (!(list_cp = malloc(sizeof(*list_cp))))
		return (0);
	*list_cp = (char *)list;
	arg_init(&arg);
	va_start(args, list);
	while (next_arg(list_cp, &arg, args, &nbc))
	{
		print_arg(args, arg, &nbc);
		arg_init(&arg);
	}
	va_end(args);
	return (nbc);
}
