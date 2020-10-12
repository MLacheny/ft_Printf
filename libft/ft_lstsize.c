/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 19:17:25 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/03 19:24:50 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*elem;
	int		i;

	i = 0;
	elem = lst;
	while (elem)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}
