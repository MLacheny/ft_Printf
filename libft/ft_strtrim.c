/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:25:38 by mlacheny          #+#    #+#             */
/*   Updated: 2020/05/31 18:58:52 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

static char	*ft_alloc_trim(int i, int j)
{
	char *dest;

	if (j > i)
	{
		if (!(dest = malloc((j - i + 2) * sizeof(*dest))))
			return (0);
		dest[0] = 1;
	}
	else
	{
		if (!(dest = malloc(sizeof(*dest))))
			return (0);
		dest[0] = 0;
		return (dest);
	}
	return (dest);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen((char *)s1) - 1;
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	while (j >= 0 && ft_isset(s1[j], set))
		j--;
	dest = ft_alloc_trim(i, j);
	if (!(dest))
		return (0);
	if (!(dest[0]))
		return (dest);
	k = 0;
	while (k + i <= j)
	{
		dest[k] = s1[k + i];
		k++;
	}
	dest[k] = 0;
	return (dest);
}
