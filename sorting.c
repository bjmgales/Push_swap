/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:47:36 by bgales            #+#    #+#             */
/*   Updated: 2022/06/28 16:32:59 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	t_lst	*b_ptr;
	int		position;
	int		tmp;

	a_ptr = *sa;
	tmp_ptr = *sa;
	b_ptr = *sb;
	tmp = 0;
	while (tmp_ptr->next != NULL)
	{
		tmp_ptr = tmp_ptr->next;
		if (a_ptr->content > tmp_ptr->content)
		{
				a_ptr = tmp_ptr;
			printf("!%d\n", a_ptr->content);
		}
	}
	position = get_position(*sa, a_ptr->content);
	tmp_ptr = *sa;
	tmp = a_ptr->content;
	while (tmp_ptr->content != tmp)
	{
		if (position > ft_listsize(*sa) / 2)
		{
			tmp_ptr = *sa;
			sa = rev_rotate(sa, 'a');
		}
		else
			rotate(sa, 'a');
	}
	push_out(&(*sa)->next, sb, 'b');
	print_list(*sa);
}