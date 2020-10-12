/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:28:31 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/02 17:34:04 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printnbr(char *dest, int n, int mode)
{
	if (mode == 0)
	{
		if (n / 10 != 0)
		{
			return (ft_printnbr(dest, n / 10, 0) + 1);
		}
		else
			return (1);
	}
	else
	{
		if (n / 10 != 0)
			ft_printnbr(dest - 1, n / 10, 1);
		*dest = n % 10 + '0';
	}
	return (0);
}

static char	*ft_handle_underflow(void)
{
	char *dest;

	if (!(dest = malloc(12 * sizeof(*dest))))
		return (0);
	dest[0] = '-';
	dest[1] = '2';
	dest[2] = '1';
	dest[3] = '4';
	dest[4] = '7';
	dest[5] = '4';
	dest[6] = '8';
	dest[7] = '3';
	dest[8] = '6';
	dest[9] = '4';
	dest[10] = '8';
	dest[11] = 0;
	return (dest);
}

char		*ft_itoa(int n)
{
	char	*dest;
	int		is_neg;
	int		size;

	is_neg = 0;
	if (n == -2147483648)
		return (ft_handle_underflow());
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	size = ft_printnbr("", n, 0);
	if (!(dest = malloc((size + 1 + is_neg) * sizeof(*dest))))
		return (0);
	if (is_neg)
		dest[0] = '-';
	ft_printnbr(dest + is_neg + size - 1, n, 1);
	dest[size + is_neg] = 0;
	return (dest);
}
