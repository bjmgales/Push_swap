/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:41:26 by bgales            #+#    #+#             */
/*   Updated: 2023/04/30 11:58:57 by bgales           ###   ########.fr       */
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

int	arg_nbr(char **argv)
{
	int	i;

	i = -1;
	while (argv[i])
		i++;
	return (i);
}

void	free_lst(t_lst *stack)
{
	t_lst	*ptr;

	while (stack->next != NULL)
	{
		ptr = stack;
		stack = stack->next;
		free (ptr);
	}
}