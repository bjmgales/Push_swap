/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:35:20 by bgales            #+#    #+#             */
/*   Updated: 2022/06/27 11:45:52 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
char **get_quote(char *argv)
{
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(argv, ' ');

	while (strs[i])
		i++;
	if (i < 3)
		print_and_exit("Error\nNot enough numbers.\n");
	return (strs);
}


void	parse(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if ((argv[i] < 48 || argv[i] > 57) && (argv[i] != 43 && argv[i] != 45 && argv[i] != 32))
			print_and_exit("Error\nWrong characters.\n");
		if ((argv[i] == 43 || argv[i] == 45) && (argv[i + 1] < 48 || argv[i + 1] > 57))
			print_and_exit("Error\nSign followed by wrong character.\n");
		if (i > 0 && (argv[i] == 43 || argv[i] == 45) && (argv[i - 1] != 32))
			print_and_exit("Error\nSign preceded by wrong character.\n");
	}
	return;

}

void	parsing(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
		parse(argv[1]);
	else
		while (argv[++i])
	 		parse(argv[i]);
	return;
}

void	already_sorted(t_lst **sa)
{
	t_lst	*ptr;
	t_lst	*tmp;

	ptr = *sa;
	tmp = *sa;
	ptr = ptr->next;
	while (tmp->next != NULL && tmp->content < ptr->content)
	{
		ptr = ptr->next;
		if (ptr->next == NULL)
		{
			tmp = tmp->next;
			ptr = tmp->next;
		}
	}
	tmp = tmp->next;
	if (tmp->next == NULL)
		print_and_exit("Error\nStack is already sorted.\n");
}

void	num_parse(t_lst **sa)
{
	t_lst	*ptr;
	t_lst	*tmp;

	ptr = *sa;
	tmp = *sa;
	ptr = ptr->next;
	while(ptr->next != NULL)
	{
			if (tmp->content == ptr->content)
			print_and_exit("Error\nA number is appearing twice.\n");
			ptr = ptr->next;
		if (ptr->next == NULL)
		{
			tmp = tmp->next;
			ptr = tmp->next;
		}
	}
	already_sorted(sa);
	return;
}