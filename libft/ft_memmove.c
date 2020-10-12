/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:19:38 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/11 17:53:15 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t i;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		i = len;
		while (i-- != 0)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	}
	else
	{
		i = -1;
		while (++i < len)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	}
	return (dst);
}
