/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:44:16 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/03 16:31:11 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_handle_underflow(int fd)
{
	write(fd, "-2147483648", 11);
}

void		ft_putnbr_fd(int n, int fd)
{
	int digit;

	if (n == -2147483648)
	{
		ft_handle_underflow(fd);
		return ;
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		if (n / 10 != 0)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		digit = n % 10 + '0';
		write(fd, &digit, 1);
	}
}
