/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:14:26 by bgales            #+#    #+#             */
/*   Updated: 2022/06/27 12:30:24 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_lst *lst)
{
	if (!lst)
		return ;
	lst->content = '\0';
	free (lst);
	return ;
}

void	ft_lstclear(t_lst **lst)
{
	t_lst	*todel;

	todel = *lst;
	while (todel != NULL)
	{
		ft_lstdelone(todel);
		todel = todel->next;
	}
	*lst = NULL;
	return ;
}
