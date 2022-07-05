/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2022/07/05 12:27:25 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_lst
{
	int		content;
	struct s_lst	*next;
} t_lst;

void	find_biggest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr);
int		get_position(t_lst *sa, int content);
void 	three_sort(t_lst **sa);
void	find_smallest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr);
int		ft_listsize(t_lst *lst);
void	sort(t_lst **sa, t_lst **sb);
void	ft_lstdelone(t_lst *lst);
void	ft_lstclear(t_lst **lst);
void	print_list(t_lst *lst);
void	print_and_exit(char *str);
void	push_out(t_lst **in, t_lst **out, int mode);
void	swap(t_lst **in, int mode);
char	**get_quote(char *argv);
void	free_lst(t_lst *stack);
void	rev_rotate(t_lst **in, int mode);
void	sorting(t_lst **sa, t_lst **sb);
void	rotate(t_lst **in, int mode);
void	swap_both(t_lst **sa, t_lst **out);
void	rev_rotate_both(t_lst **sa, t_lst **sb);
void	parsing(int argc, char **argv);
void	num_parse(t_lst **sa);
void	stack_init(t_lst **sa, t_lst **sb, t_lst **first_a, t_lst ** first_b, char **argv);

#endif