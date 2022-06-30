/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:35:14 by bgales            #+#    #+#             */
/*   Updated: 2022/06/30 15:40:11 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void push_out(t_lst **in, t_lst **out, int mode)
{
	t_lst	*tmp=malloc(sizeof(t_lst));
	tmp->next = *out;
	*out = tmp;
	tmp->content = (*in)->content;
	*in = (*in)->next;
	if (mode == 'b')
		ft_printf("pb\n");
	if (mode == 'a')
		ft_printf("pa\n");
	tmp=NULL;
	free(tmp);
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
	free(tmp);
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

void	rev_rotate(t_lst **in, int mode)
{
	t_lst	*in_ptr;
	t_lst	*f_ptr;
	int last;

	f_ptr = *in;
	in_ptr = *in;
	f_ptr->next = in_ptr;
	while(in_ptr->next->next != NULL)
		in_ptr = in_ptr->next;
	last = in_ptr->content;
	in_ptr->next = NULL;
	in_ptr = f_ptr;
	*in = in_ptr;
	free_lst(&f_ptr);
	(*in)->content = last;
	if (mode == 'a')
		ft_printf("rra\n");
	if (mode == 'b')
		ft_printf("rrb\n");
	printf("lol\n");
	return ;
}