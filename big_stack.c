/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:07:30 by bgales            #+#    #+#             */
/*   Updated: 2022/07/11 16:29:34 by bgales           ###   ########.fr       */
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
int	*get_tab(char **argv)
{
	int *tab;
	int i = 0;

	while (argv[i])
		i++;
	tab = malloc(sizeof(int) * i);
	i = -1;
	while (argv[++i])
	{
		tab[i] = ft_atoi(argv[i]);
	}
	tab = sort_tab(tab, i);
	return (tab);
}
void	big_stack_sort(t_lst **sa, t_lst **sb)
{
	int tmp;

	if (ft_listsize(*sa) < 500)
		tmp = ft_listsize(*sa) / 5;
	else
		tmp = ft_listsize(*sa) / 11;
		big_stack_next(sa, sb, tmp);
		big_stack_next(sa, sb, --tmp);
	print_list(*sb);
		big_stack_next(sa, sb, --tmp);

	return;
}