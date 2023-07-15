/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:48:01 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/15 15:35:38 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	checkleaks()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_god	*data;
	int i;

	i = 0;
	// atexit(checkleaks);
	data = parse(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	data->check_death = malloc(sizeof(pthread_t));
	// freelosopher(data);
	start_sim(data);
	
	return (0);
}
