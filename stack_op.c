/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:35:14 by bgales            #+#    #+#             */
/*   Updated: 2022/06/28 16:30:57 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_out(t_lst **in, t_lst **out, int mode)
{
	t_lst *tmp=malloc(sizeof(t_lst));
	t_lst *temp;

	tmp->next = *out;
	*out = tmp;
	temp = *in;
	tmp->content = temp->content;
	*in = (*in)->next;
	if (mode == 'b')
		ft_printf("pb\n");
	if (mode == 'a')
		ft_printf("pa\n");
	return ;
}

void	swap(t_lst **in, int mode)
{
	t_lst	*tmp = malloc(sizeof(t_lst));

	tmp->next = malloc(sizeof(t_lst));
	if (mode == 'a')
		ft_printf("sa\n");
	if (mode == 'b')
		ft_printf("sb\n");
	tmp->content = (*in)->content;
	tmp->next->content = (*in)->next->content;
	(*in)->next->content = tmp->content;
	(*in)->content = tmp->next->content;
	free (tmp);
	return ;
}

void rotate(t_lst **in, int mode)
{
	t_lst *last;
	t_lst *i;

	last = *in;
	i = *in;

	while (last->next != NULL)
		last = last->next;
	last->content = (*in)->content;
	while (i->next != NULL)
	{
		i->content = i->next->content;
		i = i->next;
	}
	if (mode == 'a')
		ft_printf("ra\n");
	if (mode == 'b')
		ft_printf("rb\n");
	return ;
}

void	rev_rot(t_lst **ret, t_lst **in, int first, int last)
{
	t_lst	*ret_ptr;
	t_lst	*in_ptr;

	ret_ptr = *ret;
	ret_ptr->content = last;
	ret_ptr = ret_ptr->next;
	ret_ptr->content = first;
	in_ptr = *in;
	in_ptr = in_ptr->next;
	while (in_ptr->next->next != NULL)
	{
		ret_ptr = ret_ptr->next;
		ret_ptr->content = in_ptr->content;
		in_ptr = in_ptr->next;
	}
	return;
}

t_lst	**rev_rotate(t_lst **in, int mode)
{
	t_lst 	**ret=NULL;
	t_lst	*in_ptr;
	t_lst	*ret_ptr;
	int first;
	int last;

	if (mode == 'a')
		ft_printf("rra\n");
	if (mode == 'b')
		ft_printf("rrb\n");
	ret = malloc(sizeof(t_lst));
	*ret = malloc(sizeof(t_lst));
	ret_ptr = (*ret);
	in_ptr = *in;
	first = in_ptr->content;
	while (in_ptr->next->next != NULL)
	{
		in_ptr = in_ptr->next;
		ret_ptr->next = malloc(sizeof(t_lst));
		ret_ptr = ret_ptr->next;
	}
	ret_ptr->next = malloc(sizeof(t_lst));
	ret_ptr->next->next = NULL;
	ret_ptr = *ret;
	last = in_ptr->content;
	rev_rot(ret, in, first, last);
	return (ret);
}