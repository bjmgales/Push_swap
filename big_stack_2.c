/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:47:36 by bgales            #+#    #+#             */
/*   Updated: 2022/07/13 13:00:57 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void top_b_min(t_lst **sb)
{
	t_lst	*tmp;
	t_lst	*a_ptr;
	int		temp;
	if (!*sb)
		return;
	print_list(*sb);
	find_smallest(*sb, &tmp, &a_ptr);
	temp = a_ptr->content;
	tmp = *sb;
	while (tmp->content != temp)
	{
		if (a_ptr->position > ft_listsize(*sb) / 2)
			rev_rotate(sb, 'b');
		else
			rotate(sb, 'b');
		 printf("lol\n");
	}

}

int	get_index(t_lst **sa, int position)
{
	t_lst	*tmp;

	tmp = *sa;
	while (tmp->position != position)
		tmp = tmp->next;

	return (tmp->index);
}
void	stack_op(t_lst **sa, t_lst **sb, int position)
{
	int tmp;
		print_list(*sa);
	while ((*sa)->index != get_index(sa, position))
	{
		if (position > ft_listsize(*sa) / 2)
			rev_rotate(sa, 'c');
		else
			rotate(sa, 'c');
	}
	printf("lol\n");
	top_b_min(sb);
	push_out(sa, sb, 'b');
}
int	find_shortest_push(int *positions, int tabSize, int listSize)
{
	int	i;
	int tmp;
	int	*moves_number;

	i = -1;
	moves_number = malloc(sizeof(int) * (tabSize + 1));

	while (++i < tabSize)
	{
		if (positions[i] > listSize / 2)
			moves_number[i] = listSize - positions[i];
		else
			moves_number[i] = positions[i];
	}
	tabSize = 0;
	tmp = INT32_MAX;
	while (tabSize < i)
	{
		if(tmp > moves_number[tabSize])
			tmp = moves_number[tabSize];
		tabSize++;
	}
	i = 0;
	while (tmp != moves_number[i])
		i++;
		free(moves_number);
	return (positions[i]);
}
void	reposition(t_lst **sa, t_lst **sb)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *sa;
	while (tmp != NULL)
	{
		tmp->position = i++;
		tmp = tmp->next;
	}
	i = 0;
	tmp = *sb;
	while (tmp != NULL)
	{
		tmp->position = i++;
		tmp = tmp->next;
	}
	return;
}

void	big_stack_next(t_lst **sa, t_lst **sb, int chunks)
{
	t_lst	*tmp;
	int		*positions;
	int		i;

	i = -1;
	tmp = *sa;
	positions = malloc(sizeof(int) * chunks);
	while(tmp != NULL)
	{
		if (tmp->index < chunks)
		 		positions[i++] = tmp->position;
		tmp = tmp->next;
	}
	stack_op(sa, sb, find_shortest_push(positions, i, ft_listsize(*sa)));
	reposition(sa, sb);
	free (positions);
}