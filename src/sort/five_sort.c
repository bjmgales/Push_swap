/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:44:26 by bgales            #+#    #+#             */
/*   Updated: 2022/07/30 14:16:09 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort(t_lst **sa, t_lst **sb)
{
	while (ft_listsize(*sa) != 3)
		sorting(sa, sb);
	three_sort(sa);
	push_out(sb, sa, 'a');
	push_out(sb, sa, 'a');
	return ;
}
