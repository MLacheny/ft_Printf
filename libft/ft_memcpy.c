/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:17:32 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/11 17:50:41 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t i;

	if (!dst && !src)
		return (0);
	i = -1;
	while (++i < n)
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	return (dst);
}
