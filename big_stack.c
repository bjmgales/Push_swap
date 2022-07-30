/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:07:30 by bgales            #+#    #+#             */
/*   Updated: 2022/07/30 15:12:24 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_in_tab(int *tab, int tmp, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (tab[i] == tmp)
			return (1);
	return (0);
}

int	biggest_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = tab[0];
	while (++i < size)
		if (tmp < tab[i])
				tmp = tab[i];
	return (tmp);
}

int	*sort_tab(int *tab, int size)
{
	int	*sort;
	int	i;
	int	c;
	int	tmp;
	int	biggest;

	sort = malloc(sizeof(int) * size);
	i = -1;
	c = 0;
	biggest = biggest_tab(tab, size);
	tmp = tab[c];
	while (c < size)
	{
		while (++i < size)
			if (tmp > tab[i] && !already_in_tab(sort, tab[i], c))
				tmp = tab[i];
		if (!already_in_tab(sort, tmp, c))
			sort[c++] = tmp;
		tmp = biggest;
		i = -1;
	}
	free(tab);
	return (sort);
}

int	*get_tab(char **argv)
{
	int	*tab;
	int	i;

	i = 0;
	while (argv[i])
		i++;
	tab = malloc(sizeof(int) * i);
	i = -1;
	while (argv[++i])
		tab[i] = ft_atoi(argv[i]);
	tab = sort_tab(tab, i);
	return (tab);
}

void	big_stack_sort(t_lst **sa, t_lst **sb, int *tab, int tabSize)
{
	int	tmp;

	if (ft_listsize(*sa) < 500)
		tmp = ft_listsize(*sa) / 5;
	else
		tmp = ft_listsize(*sa) / 11;
	while (ft_listsize(*sa) != 0)
	{
		big_stack_next(sa, sb, tmp++);
		reposition(sa, tab, tabSize);
		reposition(sb, tab, tabSize);
	}
	while (ft_listsize(*sb) != 0)
		endgame(sa, sb);
	return ;
}
