/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:36:40 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/02 18:10:08 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	if (!(dest = malloc((ft_strlen((char *)s) + 1) * sizeof(*dest))))
		return (0);
	i = -1;
	while (s[++i])
		dest[i] = (*f)((unsigned int)i, s[i]);
	dest[i] = 0;
	return (dest);
}
