/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_shit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:41:26 by bgales            #+#    #+#             */
/*   Updated: 2022/07/30 13:49:01 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listsize(t_lst *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	print_list(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		printf("%d Element in list : %d. Index = %d\n", tmp->position,
			tmp->content, tmp->index);
		tmp = tmp->next;
	}
	return ;
}

int	arg_nbr(char **argv)
{
	int	i;

	i = -1;
	while (argv[i])
		i++;
	return (i);
}
