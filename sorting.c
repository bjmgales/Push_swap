/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:47:36 by bgales            #+#    #+#             */
/*   Updated: 2022/07/04 16:19:34 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr)
{
	*tmp_ptr = sa;
	*a_ptr = sa;
	while ((*tmp_ptr)->next != NULL)
	{
		if ((*a_ptr)->content > (*tmp_ptr)->content)
			*a_ptr = *tmp_ptr;
		*tmp_ptr = (*tmp_ptr)->next;
	}
	return;
}
int	get_position(t_lst *sa, int content)
{
	int i;
	i = 0;
	while (sa->content != content)
	{
		sa = sa->next;
		i++;
	}
	return (i);
}

void	sorting(t_lst **sa, t_lst **sb)
{
	t_lst	*a_ptr;
	t_lst	*tmp_ptr;
	int		position;
	int		tmp;

	find_smallest(*sa, &tmp_ptr, &a_ptr);
	position = get_position(*sa, a_ptr->content);
	tmp = a_ptr->content;

	tmp_ptr = *sa;
	while ((*sa)->content != tmp)
	{
		if (position > ft_listsize(*sa) / 2)
			rev_rotate(sa, 'a');
		else
			rotate(sa, 'a');
	}
		push_out(sa, sb, 'b');
	return;
}

void	sort(t_lst **sa, t_lst **sb)
{
	int	tmp;

	tmp = ft_listsize(*sa);
	while (ft_listsize(*sb) != tmp)
		sorting(sa, sb);
	while(ft_listsize(*sa) != tmp)
		push_out(sb, sa, 'a');
	return;
}