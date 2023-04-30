/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:53:25 by bgales            #+#    #+#             */
/*   Updated: 2023/04/30 11:58:54 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_and_exit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	write(2, "\n", 1);
	exit (0);
}



t_lst	*stack_init(int argc, char **argv)
{
	t_lst	*head;
	t_lst	*list;

	list = malloc(sizeof(*list));
	head = list;
	argc = -1;
	while (argv[++argc])
	{
		list->content = ft_atoi(argv[argc]);
		if (!argv[argc + 1])
			break ;
		list->next = malloc(sizeof(*list));
		list = list->next;
	}
	list->next = NULL;
	return (head);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	int		*sorted;

	if (argc == 1)
		exit (0);
	argv++;
	if (argc == 2)
		argv = get_quote(argv[0]);
	parsing(argc, argv);
	stack_a = stack_init(argc, argv);
	if (stack_a->next == NULL)
		exit(0);
	num_parse(&stack_a);
	sorted = get_tab(argv);
	reposition(&stack_a, sorted, ft_listsize(stack_a));
	sort(&stack_a, &stack_b, sorted);
	exit (0);
}
