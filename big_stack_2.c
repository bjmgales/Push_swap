/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:47:36 by bgales            #+#    #+#             */
/*   Updated: 2022/07/16 16:06:05 by bgales           ###   ########.fr       */
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
	find_smallest(*sb, &tmp, &a_ptr);
	temp = a_ptr->content;
	tmp = *sb;
	while (tmp->content != temp)
	{
		if (a_ptr->position > ft_listsize(*sb) / 2)
			rev_rotate(sb, 'b');
		else
			rotate(sb, 'b');
	}

}

int	get_content(t_lst **sa, int position)
{
	t_lst	*tmp;

	tmp = *sa;
	while (tmp->position != position)
		tmp = tmp->next;
	return (tmp->content);
}
void	stack_op(t_lst **sa, t_lst **sb, int position)
{
	int tmp;

	tmp = get_content(sa, position);
	while ((*sa)->content != tmp)
	{
		if (position > ft_listsize(*sa) / 2)
			rev_rotate(sa, 'a');
		else
			rotate(sa, 'a');
	}
	top_b_min(sb);
	push_out(sa, sb, 'b');
	return ;
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
	while (tmp != moves_number[i] && i < tabSize)
		i++;
	if (i != 0)
		free(moves_number);
	return (positions[i]);
}
void	reposition(t_lst **sa, t_lst **sb, int *tab, int tabSize)
{
	t_lst	*tmp;
	int		i;
	int		c;

	i = 0;
	c = 0;
	tmp = *sa;
	while (tmp != NULL)
	{
		tmp->position = i++;
		while (tmp->content != tab[c] && c < tabSize)
			c++;
		if (tmp->content == tab[c])
			tmp->index = c;
		c = 0;
		tmp = tmp->next;
	}
	i = 0;
	tmp = *sb;
	while (tmp != NULL)
	{
		tmp->position = i++;
		while (tmp->content != tab[c] && c < tabSize)
			c++;
		if (tmp->content == tab[c])
			tmp->index = c;
		c = 0;
		tmp = tmp->next;
	}
	return;
}

void	big_stack_next(t_lst **sa, t_lst **sb, int chunks)
{
	t_lst	*tmp;
	int		*positions;
	int		i;

	if (ft_listsize(*sa) == 1)
	{
		top_b_min(sb);
		push_out(sa, sb, 'b');
		return;
	}
	i = -1;
	tmp = *sa;
	positions = malloc(sizeof(int) * (chunks) + 1);
	while(tmp != NULL)
	{
		if (tmp->index < chunks)
		 		positions[++i] = tmp->position;
		tmp = tmp->next;
	}
	stack_op(sa, sb, find_shortest_push(positions, i, ft_listsize(*sa)));
	if (i != 0)
		free (positions);
	return ;
}