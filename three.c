/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:14:32 by bgales            #+#    #+#             */
/*   Updated: 2022/07/05 12:36:07 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void final_three(t_lst **sa, int big, int small)
{
	//if (big == 2 && small == 1)
	//{
		rev_rotate(sa, 'a');
		swap(sa, 'a');
	//}
}
void three_sort(t_lst **sa)
{
	t_lst	*t_ptr;
	t_lst	*big;
	t_lst	*a_ptr;
	int		position_s;
	int		position_b;

	find_smallest(*sa, &t_ptr, &a_ptr);
	position_s = get_position(*sa, a_ptr->content);
	find_biggest(*sa, &t_ptr, &a_ptr);
	position_b = get_position(*sa, a_ptr->content);
	position_b++;
	position_s++;
	final_three(sa, position_b, position_s);
	return ;
}