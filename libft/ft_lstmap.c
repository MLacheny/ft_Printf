/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 22:30:24 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/03 22:52:07 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_cp;
	t_list	*newelem;

	if (!lst)
		return (0);
	lst_cp = ft_lstnew(f(lst->content));
	if (!lst_cp)
		return (0);
	lst = lst->next;
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (!newelem)
		{
			ft_lstclear(&lst_cp, del);
			return (0);
		}
		ft_lstadd_back(&lst_cp, newelem);
		lst = lst->next;
	}
	return (lst_cp);
}
