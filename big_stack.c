/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:07:30 by bgales            #+#    #+#             */
/*   Updated: 2022/07/08 16:04:02 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_stack_sort(t_lst **sa, t_lst **sb, int argc)
{
	if (argc < 500)
		argc /= 4;
	else
		argc /= 11;
	
	/*	while (ft_listsize(*sb) != tmp)
	{
		sorting(sa, sb);
		if(ft_listsize(*sa) == 5)
			five_sort(sa, sb);
	}
		while(ft_listsize(*sa) != tmp)
			push_out(sb, sa, 'a');*/
	return;
}