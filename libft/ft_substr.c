/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 09:18:40 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/11 19:45:07 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (start >= (unsigned int)ft_strlen((char *)s))
	{
		if (!(dest = malloc(sizeof(*dest))))
			return (0);
		*dest = 0;
		return (dest);
	}
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		dest[i] = s[i + start];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
