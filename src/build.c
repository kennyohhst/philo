/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:54:31 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/29 04:09:39 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * This function adds two integers and returns the result.
 *
 * @param a ARGC
 * @param b ARGV
 * @return 1 IF GOOD, 0 IF BAD
 */


int	check_args(int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc != 5 && argc != 6)
		return (0);
	while (x < argc)
	{
		if (!ft_numcheck(argv[x]))
			return (0);
		x++;
	}
	return (1);
}
