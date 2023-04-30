/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 01:09:24 by bgales            #+#    #+#             */
/*   Updated: 2022/06/15 11:50:09 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **last, t_list *new)
{
	t_list	*tmp;

	tmp = NULL;
	if (last)
	{
		if (*last)
		{
			tmp = ft_lstlast(*last);
			tmp->next = new;
		}
	}
	if (*last == NULL)
		*last = new;
	return ;
}
