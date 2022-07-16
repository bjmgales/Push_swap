/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:51:35 by bgales            #+#    #+#             */
/*   Updated: 2022/07/16 14:29:27 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_and_push(t_lst **sa, t_lst **sb, int big, int position)
{
	while ((*sb)->content != big)
	{
		if (position > ft_listsize(*sb) / 2)
			rev_rotate(sb, 'b');
		else
			rotate(sb, 'b');
	}
	push_out(sb, sa, 'a');
}
void	endgame(t_lst **sa, t_lst **sb)
{
	t_lst *tmp;
	t_lst *ptr;
	int big;
	int position;

	find_biggest(*sb, &tmp, &ptr);
	big = ptr->content;
	position = ptr->position;
	top_and_push(sa, sb, big, position);
}