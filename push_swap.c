/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:53:25 by bgales            #+#    #+#             */
/*   Updated: 2022/11/28 15:42:27 by bgales           ###   ########.fr       */
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

void	stack_ini(t_lst **sa, t_lst **sb, char **argv)
{
	int		i;
	t_lst	*tmp;
	t_lst	*temp;

	i = 0;
	temp = NULL;
	while (argv[i])
	{
		tmp = malloc(sizeof(t_lst));
		tmp->content = ft_atoi(argv[i]);
		*sa = tmp;
		*sb = temp;
		sa = &(tmp->next);
		i++;
	}
	*sa = NULL;
	*sb = NULL;
	return ;
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
	stack_ini(&stack_a, &stack_b, argv);
	if (stack_a->next == NULL)
		exit(0);
	num_parse(&stack_a);
	sorted = get_tab(argv);
	reposition(&stack_a, sorted, ft_listsize(stack_a));
	sort(&stack_a, &stack_b, sorted);
	exit (0);
}
