/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:35:14 by bgales            #+#    #+#             */
/*   Updated: 2022/07/30 14:16:36 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_out(t_lst **in, t_lst **out, int mode)
{
	t_lst	*tmp;

	tmp = *in;
	*in = (*in)->next;
	tmp->next = *out;
	*out = tmp;
	if (mode == 'b')
		printf("pb\n");
	if (mode == 'a')
		printf("pa\n");
	return ;
}

void	swap(t_lst **in, int mode)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	tmp->next = malloc(sizeof(t_lst));
	if (mode == 'a')
		printf("sa\n");
	if (mode == 'b')
		printf("sb\n");
	tmp->content = (*in)->content;
	tmp->next->content = (*in)->next->content;
	(*in)->next->content = tmp->content;
	(*in)->content = tmp->next->content;
	free(tmp->next);
	free(tmp);
	return ;
}

void	rotate(t_lst **in, int mode)
{
	t_lst	*last;
	t_lst	*i;
	int		tmp;

	last = *in;
	i = *in;
	while (last->next != NULL)
		last = last->next;
	tmp = (*in)->content;
	while (i->next != NULL)
	{
		i->content = i->next->content;
		i->index = i->next->index;
		i = i->next;
	}
	i->content = tmp;
	if (mode == 'a')
		printf("ra\n");
	if (mode == 'b')
		printf("rb\n");
	return ;
}

void	rev_rotate(t_lst **in, int mode)
{
	t_lst	*in_ptr;
	t_lst	*f_ptr;
	t_lst	*end;
	int		i;

	in_ptr = *in;
	end = *in;
	while (in_ptr->next->next != NULL)
		in_ptr = in_ptr->next;
	f_ptr = in_ptr->next;
	f_ptr->next = *in;
	*in = f_ptr;
	in_ptr->next = NULL;
	i = 0;
	while (end != NULL)
	{
		end->position = i++;
		end = end->next;
	}
	if (mode == 'a')
		printf("rra\n");
	if (mode == 'b')
		printf("rrb\n");
	return ;
}
