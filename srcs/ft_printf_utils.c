/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:50:35 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/05 16:38:08 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_precision(char **list, t_arg *arg, va_list args)
{
	if (**list != '.')
		return ;
	if (*(++(*list)) == '*')
	{
		arg->precision = va_arg(args, int);
		if (arg->precision < 0)
			arg->precision = -1;
		*list = *list + 1;
		return ;
	}
	arg->precision = 0;
	while ('0' <= **list && **list <= '9')
		arg->precision = arg->precision * 10 + *((*list)++) - '0';
}

void	get_conv_spec(char **list, t_arg *arg)
{
	arg->conv_spec = *((*list)++);
}

void	arg_init(t_arg *arg)
{
	arg->flag = 0;
	arg->field_width = 0;
	arg->precision = -1;
	arg->conv_spec = 0;
}
