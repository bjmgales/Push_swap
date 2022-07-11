/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:47:36 by bgales            #+#    #+#             */
/*   Updated: 2022/07/11 16:31:45 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	stack_op(t_lst **sa, t_lst **sb, int position)
{
	while ((*sa)->position != position)
	{
		if (position > ft_listsize(*sa) / 2)
			rev_rotate(sa, 'c');
		else
			rotate(sa, 'c');
		//printf("%d\n", (*sa)->index);
	}
	push_out(sa, sb, 'b');
}
int	find_shortest_push(int *tab, int chunks)
{
	int i = -1;
	int *index;
	int tmp;

	index = malloc(sizeof(int) * chunks);
	while (++i < chunks)
	{
		if (tab[i] > 50)
			index[i] = (tab[i] - 100) * -1;
		else
			index[i] = tab[i];
	}
	i = -1;
	tmp = index[0];
	while (++i < chunks - 1)
	{
		if (tmp > index[i])
		 	tmp = index[i];
	}
	return (tab[i]);
}
void	big_stack_next(t_lst **sa, t_lst **sb, int chunks)
{
	t_lst	*tmp;
	int		*index;
	int		i;

	i = -1;
	tmp = *sa;
	index = malloc(sizeof(int) * chunks);
	while(tmp != NULL)
	{
		if (tmp->index <= chunks)
		 		index[i++] = tmp->position;
		tmp = tmp->next;
	}
	printf("chunks :%d\n",chunks);
	printf("find_s_p : %d\n", find_shortest_push(index, chunks));
	print_list(*sa);
	stack_op(sa, sb, find_shortest_push(index, chunks));
	free (index);
}