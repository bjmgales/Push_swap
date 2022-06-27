/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:47:36 by bgales            #+#    #+#             */
/*   Updated: 2022/06/27 14:12:15 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_lst **sa, t_lst **sb)
{
	t_lst	*a_ptr;
	t_lst	*tmp_ptr;
	int		i;

	i = ft_listsize(*sa) / 2; // 7\2 = 3
	a_ptr = *sa;
	tmp_ptr = *sa;
	while (a_ptr->next != NULL && i >= 0)
	{
		while (a_ptr->content <= tmp_ptr->content && tmp_ptr->next != NULL)
			tmp_ptr = tmp_ptr->next;
		if (tmp_ptr->next == NULL)
		{
			push_out(&a_ptr, sb, 'b');
			i--;
			tmp_ptr = *sa;
			a_ptr = a_ptr->next;
			break;
		}
		else
			a_ptr = tmp_ptr;
		printf("%d\n", tmp_ptr->content);
	}
	print_list(*sa);
}