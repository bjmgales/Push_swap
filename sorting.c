/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:47:36 by bgales            #+#    #+#             */
/*   Updated: 2022/07/11 16:17:28 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_biggest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr)
{
	*tmp_ptr = sa;
	while ((*tmp_ptr) != NULL)
	{
		if ((*a_ptr)->content < (*tmp_ptr)->content)
			*a_ptr = *tmp_ptr;
		*tmp_ptr = (*tmp_ptr)->next;
	}
	return;
}
void	find_smallest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr)
{
	*tmp_ptr = sa;
	*a_ptr = sa;
	while ((*tmp_ptr) != NULL)
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

void	sort(t_lst **sa, t_lst **sb, int argc)
{
	int	tmp;

	tmp = ft_listsize(*sa);
	if(tmp == 2)
		swap(sa, 'a');
	if (tmp == 3)
		three_sort(sa);
	if (tmp == 5)
		five_sort(sa, sb);
	if (tmp <= 5)
		return;
	big_stack_sort(sa, sb);
}