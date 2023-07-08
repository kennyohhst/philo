/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:29:11 by code              #+#    #+#             */
/*   Updated: 2023/07/08 16:58:58 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_numcheck(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		exit(write(2, "Error\n", 6));
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit(write(2, "Error\n", 6));
		i++;
	}
}
