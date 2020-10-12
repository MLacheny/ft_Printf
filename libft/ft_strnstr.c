/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:47:55 by mlacheny          #+#    #+#             */
/*   Updated: 2020/05/29 14:31:56 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (needle[0] == haystack[i])
		{
			j = 1;
			while (needle[j] == haystack[i + j] && needle[j] && i + j < len)
				j++;
			if (!needle[j])
				return (((char *)haystack) + i);
		}
		i++;
	}
	return (0);
}
