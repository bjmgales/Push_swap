/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:18:24 by bgales            #+#    #+#             */
/*   Updated: 2022/07/01 12:05:10 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_lst **sa, t_lst **sb)
{
	swap(sa, 'c');
	swap(sb, 'c');
	return ;
}

void rotate_both(t_lst **sa, t_lst **sb)
{
	t_lst *last;
	t_lst *i;

	last = *sa;
	i = *sa;
	ft_printf("rr\n");
	while (last->next != NULL)
		last = last->next;
	last->content = (*sa)->content;
	while (i->next != NULL)
	{
		i->content = i->next->content;
		i = i->next;
	}
	last = *sb;
	i = *sb;
	while (last->next != NULL)
		last = last->next;
	last->content = (*sb)->content;
	while (i->next != NULL)
	{
		i->content = i->next->content;
		i = i->next;
	}
}

void	rev_rotate_both(t_lst **sa, t_lst **sb)
{
	rev_rotate(sa, 'c');
	rev_rotate(sb, 'c');
	ft_printf("rrr\n");
	return;
}