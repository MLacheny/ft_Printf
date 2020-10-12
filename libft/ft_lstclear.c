/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 21:45:24 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/03 22:10:25 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;
	t_list	*elem_next;

	if (!(*lst))
		return ;
	elem = *lst;
	elem_next = elem->next;
	while (elem_next)
	{
		ft_lstdelone(elem, del);
		elem = elem_next;
		elem_next = elem_next->next;
	}
	ft_lstdelone(elem, del);
	*lst = 0;
}
