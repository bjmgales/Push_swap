/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:45:59 by bgales            #+#    #+#             */
/*   Updated: 2023/04/30 12:11:26 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_lst
{
	int				content;
	int				position;
	int				index;
	struct s_lst	*next;
}	t_lst;

/**
@brief Print the given string to stderr and exit the program with status code 0.
 *
@param str The string to be printed to stderr.
 *
@return None.
 */
void print_and_exit(char *str);

/**
@brief Free the memory allocated to the given linked list and its nodes.
 *
@param stack A pointer to the head of the linked list to be freed.
 *
@return None.
 */
void free_lst(t_lst *stack);

/**
@brief Create and initialize a linked list with integers parsed from the given array of strings.
 *
@param argc The number of strings in the argv array.
@param argv An array of strings to be parsed into integers for the linked list.
 *
@return A pointer to the head of the initialized linked list.
 */
t_lst *stack_init(int argc, char **argv);

/**
@brief The entry point of the program.
 *
@param argc The number of command-line arguments.
@param argv An array of strings containing the command-line arguments.
 *
@return 0 on successful execution of the program.
 */
int main(int argc, char **argv);

/**
@brief Splits a string argument into multiple substrings based on the ' ' (space) delimiter.
@param argv A string argument to be split into substrings.
@return A pointer to an array of strings, each of which is a substring of the original string separated by a space.
 */
char **get_quote(char *argv);

/**
@brief Checks if a string argument contains only digits, '+' or '-' characters and spaces.
@param argv A string argument to be checked.
@return void
 */
void parse(char *argv);

/**
@brief Parses and checks each argument passed to the program, making sure they contain only digits, '+' or '-' characters and spaces.
@param argc The number of arguments passed to the program.
@param argv An array of strings containing the arguments passed to the program.
@return void
 */
void parsing(int argc, char **argv);

/**
@brief Checks if the given stack is already sorted in ascending order.
@param sa A pointer to the first node of a stack.
@return void
 */
void already_sorted(t_lst **sa);

/**
@brief Checks if all numbers in the stack are unique.
@param sa A pointer to the first node of a stack.
@return void
 */
void num_parse(t_lst **sa);

/**
@brief Returns the size of a linked list
 *
@param lst A pointer to the first element of the linked list
@return The number of elements in the linked list
 */
int ft_listsize(t_lst *lst);

/**
@brief Returns the number of arguments in an array of strings
 *
@param argv An array of strings
@return The number of arguments in the array of strings
 */
int arg_nbr(char **argv);

/**
@brief Moves the first element from the in stack to the top of the out stack.
 *
@param in A pointer to a pointer to the top of the in stack.
@param out A pointer to a pointer to the top of the out stack.
@param mode A character specifying the stack, 'a' for stack A, 'b' for stack B.
 */
void	push_out(t_lst **in, t_lst **out, int mode);

/**
@brief Swaps the first two elements at the top of the given stack.
 *
@param in A pointer to a pointer to the top of the stack to be swapped.
@param mode A character specifying the stack, 'a' for stack A, 'b' for stack B.
 */
void	swap(t_lst **in, int mode);

/**
@brief Shifts up all elements of the given stack by 1.
The first element becomes the last one.
 *
@param in A pointer to a pointer to the top of the stack to be rotated.
@param mode A character specifying the stack, 'a' for stack A, 'b' for stack B.
 */
void	rotate(t_lst **in, int mode);

/**
@brief Shifts down all elements of the given stack by 1.
The last element becomes the first one.
 *
@param in A pointer to a pointer to the top of the stack to be rotated.
@param mode A character specifying the stack, 'a' for stack A, 'b' for stack B.
 */
void	rev_rotate(t_lst **in, int mode);
/**

@brief Swaps the first two elements of stack a and stack b.
@param sa Pointer to the top of stack a.
@param sb Pointer to the top of stack b.
*/
void swap_both(t_lst **sa, t_lst **sb);
/**

@brief Rotates stack a and stack b simultaneously by one element.
@param sa Pointer to the top of stack a.
@param sb Pointer to the top of stack b.
*/
void rotate_both(t_lst **sa, t_lst **sb);
/**

@brief Reverses rotate stack a and stack b simultaneously by one element.
@param sa Pointer to the top of stack a.
@param sb Pointer to the top of stack b.
*/
void rev_rotate_both(t_lst **sa, t_lst **sb);

/**
@brief Top element from stack B and push it to stack A, after finding its correct position
 *
@param sa The stack A
@param sb The stack B
@param big The value of the element to be moved to stack A
@param position The position of the element to be moved in stack B
 */
void	top_and_push(t_lst **sa, t_lst **sb, int big, int position);

/**
@brief Move the biggest element from stack B to stack A, after finding its correct position
 *
@param sa The stack A
@param sb The stack B
 */
void	endgame(t_lst **sa, t_lst **sb);

/**
@brief Sorts the final three elements in the stack `sa`.
 *
@param sa A pointer to the pointer of the stack `sa`.
@param big The position of the biggest element in `sa`.
@param small The position of the smallest element in `sa`.
 */
void	final_three(t_lst **sa, int big, int small);

/**
@brief Sorts the stack `sa` when it contains only three elements.
 *
@param sa A pointer to the pointer of the stack `sa`.
 */
void	three_sort(t_lst **sa);

/**
@brief Finds the node with the biggest content in a linked list.
@param sa Pointer to the head node of the linked list.
@param tmp_ptr Pointer to the temporary node pointer to be used in the function.
@param a_ptr Pointer to the pointer to the node with the biggest content.
@return void
 */
void find_biggest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr);

/**
@brief Finds the node with the smallest content in a linked list.
@param sa Pointer to the head node of the linked list.
@param tmp_ptr Pointer to the temporary node pointer to be used in the function.
@param a_ptr Pointer to the pointer to the node with the smallest content.
@return void
 */
void find_smallest(t_lst *sa, t_lst **tmp_ptr, t_lst **a_ptr);

/**
@brief Finds the position of a node with the given content in a linked list.
@param sa Pointer to the head node of the linked list.
@param content The content to search for in the linked list.
@return The position of the node with the given content in the linked list.
 */
int get_position(t_lst *sa, int content);

/**
@brief Sorts a stack by moving the smallest node to the top and pushing it to another stack.
@param sa Pointer to the head node of the stack to sort.
@param sb Pointer to the head node of the second stack.
@return void
 */
void sorting(t_lst **sa, t_lst **sb);

/**
@brief Sorts a stack of integers using various sorting algorithms based on its size.
@param sa Pointer to the head node of the stack to sort.
@param sb Pointer to the head node of the second stack.
@param tab Pointer to the array of integers to sort.
@return void
 */
void sort(t_lst **sa, t_lst **sb, int *tab);

/**
@brief Check if an integer is already in an array.
 *
@param tab Pointer to the array to search.
@param tmp The integer to search for.
@param size The size of the array.
@return 1 if the integer is found in the array, 0 otherwise.
 */
int already_in_tab(int *tab, int tmp, int size);

/**
@brief Find the largest integer in an array.
 *
@param tab Pointer to the array to search.
@param size The size of the array.
@return The largest integer in the array.
 */
int biggest_tab(int *tab, int size);

/**
@brief Sort an integer array in ascending order.
 *
@param tab Pointer to the array to sort.
@param size The size of the array.
@return A pointer to the sorted array.
 */
int *sort_tab(int *tab, int size);

/**
@brief Convert an array of string arguments to an array of integers and sort it.
 *
@param argv Array of string arguments to convert and sort.
@return A pointer to the sorted array of integers.
 */
int *get_tab(char **argv);

/**
@brief Sort a stack of integers in ascending order using a custom algorithm for large stacks.
 *
@param sa Pointer to the stack to sort.
@param sb Unused pointer to a second stack.
@param tab Pointer to the sorted array of integers to use in sorting.
@param tabSize The size of the sorted array.
@return void
 */
void big_stack_sort(t_lst **sa, t_lst **sb, int *tab, int tabSize);

/**
@brief Sort a stack of five or fewer integers using a custom algorithm.
 *
@param sa Pointer to the stack to sort.
@param sb Unused pointer to a second stack.
@return void
 */
void five_sort(t_lst **sa, t_lst **sb);

/**
@brief Get the content at a given position in the stack
 *
@param sa Double pointer to the stack to get content from
@param position The position to retrieve the content from
 *
@return The content at the given position
 */
int	get_content(t_lst **sa, int position);

/**
@brief Perform a stack operation by pushing the top element of sa onto sb
 *
@param sa Double pointer to the stack to push from
@param sb Double pointer to the stack to push to
@param position The position of the element to be pushed from sa to sb
 *
@return void
 */
void	stack_op(t_lst **sa, t_lst **sb, int position);

/**
@brief Find the shortest distance to move an element from its current position to the top of the stack
 *
@param positions An array containing the positions of elements in the stack
@param tabSize The size of the positions array
@param listSize The total number of elements in the stack
 *
@return The position of the element that requires the shortest distance to move to the top of the stack
 */
int	find_shortest_push(int *positions, int tabSize, int listSize);

/**
@brief Update the position and index of each element in the stack based on the given array of integers
 *
@param sa Double pointer to the stack to update
@param tab Array of integers to use to update positions and indexes
@param tabSize The size of the tab array
 *
@return void
 */
void	reposition(t_lst **sa, int *tab, int tabSize);

/**
@brief Perform a stack operation on a large stack by pushing a subset of the elements from sa onto sb
 *
@param sa Double pointer to the stack to push from
@param sb Double pointer to the stack to push to
@param chunks The size of the subset of elements to push from sa to sb
 *
@return void
 */
void	big_stack_next(t_lst **sa, t_lst **sb, int chunks);

#endif
