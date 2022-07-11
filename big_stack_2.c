/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:47:36 by bgales            #+#    #+#             */
/*   Updated: 2022/07/10 16:07:30 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	big_stack_next(t_lst **sa, t_lst **sb, int *tab, int chunks)
{
	t_lst	*tmp;
	int		*index;
	int		i;

	i = 0;
	tmp = *sa;
	index = malloc(sizeof(int) *chunks);

	while (ft_listsize(sa) != 0)
	{
		while (i < chunks)
		{
			while(tmp != tab[i])
				tmp = tmp->next;
			index[i] = tmp->index;
			i++;
			tmp = *sa;
		}
		chunks *= 2
		while (i)
	}
}