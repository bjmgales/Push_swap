/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_shit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:41:26 by bgales            #+#    #+#             */
/*   Updated: 2022/07/08 11:40:23 by bgales           ###   ########.fr       */
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

void	stack_init(t_lst **sa, t_lst **sb, t_lst **first_a, t_lst **first_b, char **argv)
{
	int	i;

	i = 0;
	(*first_a) = malloc(sizeof(t_lst) * 1);
	(*first_b) = malloc(sizeof(t_lst) * 1);
	(*sa) = malloc(sizeof(t_lst) * 1);
	(*sb) = malloc(sizeof(t_lst) * 1);
	(*sa)->content = ft_atoi(argv[i]);
	(*first_a) = (*sa);
	(*first_b) = (*sb);
	while (argv[++i])
	{
		(*sa)->next = malloc(sizeof(t_lst) * 1);
		(*sb)->next = malloc(sizeof(t_lst) * 1);
		(*sa)->content = ft_atoi(argv[i]);
		(*sa) = (*sa)->next;
		(*sb) = (*sb)->next;
	}
	(*sa)->next=NULL;
	(*sb)->next=NULL;
	return;
}

void	print_list(t_lst *lst)
{
	int i = 0;
	t_lst *tmp;
	tmp = lst;
	while (tmp != NULL)
	{
		printf("%d Element in list : %d\n",i++, tmp->content);
		tmp = tmp->next;
	}
	return ;
}
