/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:53:25 by bgales            #+#    #+#             */
/*   Updated: 2022/06/29 13:13:54 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_and_exit(char *str)
{
	ft_printf("%s", str);
	exit (0);
}

void	free_lst(t_lst **stack)
{
	if (*stack)
	{
		free_lst(&(*stack)->next);
		free(*stack);
	}
	free (stack);
}
void	stack_ini(t_lst **sa, t_lst **sb, char **argv)
{
	int	i;
	t_lst *tmp;
	t_lst *temp;

	i = 0;
	tmp = *sa;
	temp = *sb;

	while (argv[i])
	{
		tmp->content = ft_atoi(argv[i]);
		tmp->next = malloc(sizeof(t_lst));
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	temp->next = NULL;
	return ;
}
int main(int argc, char **argv)
{
	t_lst *stack_a;
	t_lst *stack_b;

	if (argc < 2 || argc > 501 || argc == 3)
		print_and_exit("Error\n Argument number is invalid\n");
	parsing(argc, argv);
	argv++;
	if (argc == 2)
		argv = get_quote(argv[0]);
	stack_a = malloc(sizeof(t_lst));
	stack_b = malloc(sizeof(t_lst));
	stack_ini(&stack_a, &stack_b, argv);
	num_parse(&stack_a);
	sort(&stack_a, &stack_b);
	return 0;
}
