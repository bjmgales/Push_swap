/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:27:38 by bgales            #+#    #+#             */
/*   Updated: 2022/07/30 13:55:20 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../push_swap.h"

void	ok_quote(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((str[i] <= 47 || str[i] >= 58) && (str[i] != '-' && str[i] != '+'))
			print_and_exit("Error");
}

int	ft_atoi(const char *str)
{
	long	signe;
	long	resultat;
	int		i;

	signe = 1;
	resultat = 0;
	i = 0;
	ok_quote(str);
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		resultat = (resultat * 10) + (str[i] - 48);
		i++;
	}
	if (resultat * signe > __INT32_MAX__ || resultat * signe < INT32_MIN)
		print_and_exit("Error");
	return (resultat * signe);
}
