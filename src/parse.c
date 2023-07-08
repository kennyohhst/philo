/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:54:31 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/08 19:56:22 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	basic_data(t_god **temp, int argc, char **argv)
{
	add_philos(temp, argv[1]);
	add_death(temp, argv[2]);
	add_eat(temp, argv[3]);
	add_sleep(temp, argv[4]);
	if (argc == 6)
		add_eating_amount(temp, argv[5]);
}

void	check_args(int argc, char **argv)
{
	int x;
	
	x = 1;
	if (argc != 5 && argc != 6)
		exit(write(STDERR_FILENO, "Error check input amount\n", 26));
	while (x < argc)
	{
		ft_numcheck(argv[x]);
		x++;
	}
}

t_god	*parse(int argc, char **argv)
{
	t_god	*temp = malloc(sizeof(t_god));
	check_args(argc, argv);
	basic_data(&temp, argc, argv);
	// build_table(&temp);
	// build_philos(&temp);
	return(temp);
}