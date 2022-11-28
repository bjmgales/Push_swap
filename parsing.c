/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:35:20 by bgales            #+#    #+#             */
/*   Updated: 2022/11/28 17:32:18 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_quote(char *argv)
{
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(argv, ' ');
	while (strs[i])
		i++;
	if (!strs[0])
		exit(0);
	if (i < 1)
		exit (0);
	return (strs);
}

void	parse(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if ((argv[i] < 48 || argv[i] > 57) && (argv[i] != 43
				&& argv[i] != 45 && argv[i] != 32))
			print_and_exit("Error");
		if ((argv[i] == 43 || argv[i] == 45) && (argv[i + 1]
				< 48 || argv[i + 1] > 57))
			print_and_exit("Error");
		if (i > 0 && (argv[i] == 43 || argv[i] == 45) && (argv[i - 1] != 32))
			print_and_exit("Error");
	}
	return ;
}

void	parsing(int argc, char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		ft_atoi(argv[i]);
	i = -1;
	if (argc == 2)
		parse(argv[0]);
	else
		while (argv[++i])
			parse(argv[i]);
	return ;
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
		if (ptr == NULL)
		{
			tmp = tmp->next;
			ptr = tmp->next;
		}
	}
	if (tmp->next == NULL)
		exit(0);
}

void	num_parse(t_lst **sa)
{
	t_lst	*ptr;
	t_lst	*tmp;

	tmp = *sa;
	ptr = (*sa)->next;
	while (tmp->next != NULL)
	{
		if (tmp->content == ptr->content)
			print_and_exit("Error");
		ptr = ptr->next;
		if (ptr == NULL)
		{
			tmp = tmp->next;
			ptr = tmp->next;
		}
	}
	already_sorted(sa);
	return ;
}
