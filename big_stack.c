/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:07:30 by bgales            #+#    #+#             */
/*   Updated: 2022/07/09 14:05:11 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	already_in_tab(int *tab, int tmp)
{
	int	i;
	i = -1;

	while(tab[++i])
	{
		if(tmp == tab[i])
			return (1);
	}
	return (0);
}
void	smallest_for_tab(t_lst *sa, t_lst *tmp, t_lst	*a_ptr, int *tab)
{
	int	i;
	int t = 0;

	i = 0;
	tmp = sa;
	a_ptr = sa;
	while (i != ft_listsize(sa) - 1)
	{
		if (tmp == NULL)
		{
			tmp = sa;
			a_ptr = sa;
		}
		printf("%d\n", a_ptr->content);
			if ((a_ptr)->content > (tmp)->content && !already_in_tab(tab, a_ptr->content))
			{
				a_ptr = tmp;
				tab[i++] = (a_ptr)->content;
			}
		tmp = tmp->next;
	}
	return;
}
void	get_tab(t_lst **sa)
{
	int		*tab;
	t_lst	*tmp;
	t_lst	*a_ptr;
	int		i = -1;
	tab = malloc(sizeof(int) * (ft_listsize(*sa) + 1));
	tab[ft_listsize(*sa) + 1] = '\0';
	smallest_for_tab(*sa, tmp, a_ptr, tab);
	 while(tab[++i])
	 	printf("%d\n", tab[i]);

}
void	big_stack_sort(t_lst **sa, t_lst **sb, int argc)
{
	if (argc < 500)
		argc /= 4;
	else
		argc /= 11;
	get_tab(sa);
/*	while (ft_listsize(*sb) != tmp)
	{
		sorting(sa, sb);
		if (ft_listsize(*sa) == 5)
			five_sort(sa, sb);
	}
		while(ft_listsize(*sa) != tmp)
			push_out(sb, sa, 'a');*/
	return;
}