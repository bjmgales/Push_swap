/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:45:59 by bgales            #+#    #+#             */
/*   Updated: 2022/07/30 15:11:44 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_lst
{
	int				content;
	int				position;
	int				index;
	struct s_lst	*next;
}	t_lst;

void	endgame(t_lst **sa, t_lst **sb);
void	reposition(t_lst **sa, int *tab, int tabSize);
int		*get_tab(char **argv);
int		arg_nbr(char **argv);
void	big_stack_next(t_lst **sa, t_lst **sb, int chunks);
void	big_stack_sort(t_lst **sa, t_lst **sb, int *tab, int tabSize);
void	five_sort(t_lst **sa, t_lst **sb);
void	find_biggest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr);
int		get_position(t_lst *sa, int content);
void	three_sort(t_lst **sa);
void	find_smallest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr);
int		ft_listsize(t_lst *lst);
void	sort(t_lst **sa, t_lst **sb, int *tab);
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

#endif