/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:07:30 by bgales            #+#    #+#             */
/*   Updated: 2022/07/10 16:03:37 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_in_tab(int *tab, int tmp, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] == tmp)
			return (1);
	return (0);
}

int biggest_tab(int *tab, int size)
{
	int i;
	int tmp;

	i = -1;
	tmp = tab[0];
	while (++i < size)
		if (tmp < tab[i])
				tmp = tab[i];
	return (tmp);
}
int		*sort_tab(int *tab, int size)
{
	int *sort = malloc(sizeof(int) * size);
	int i = -1;
	int c = 0;
	int tmp;
	int biggest;

	biggest = biggest_tab(tab, size);
	tmp = tab[c];
	while (c < size)
	{
		while(++i < size)
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
int	*get_tab(t_lst *sa)
{
	int *tab;
	int i = 0;
	int tmp = ft_listsize(sa);
	tab = malloc(sizeof(int) * ft_listsize(sa));
	while (sa != NULL)
	{
		tab[i] = sa->content;
		i++;
		sa = sa->next;
	}
	tab = sort_tab(tab, tmp);
	return (tab);
}
void	big_stack_sort(t_lst **sa, t_lst **sb)
{
	int	*tab;
	int tmp;

	if (ft_listsize(sa) < 500)
		tmp = ft_listsize(sa) / 4;
	else
		tmp = ft_listsize / 11;

	tab = get_tab(*sa);
	big_stack_next(sa, sb, tab, tmp);
	return;
}