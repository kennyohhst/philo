/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:54:31 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/10 23:14:09 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	make_round(t_table *table)
{
	t_table	*temp;
	
	temp = table;
	while (temp->next != NULL)
	{
		temp->l_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(temp->l_fork, NULL);
		temp = temp->next;
	}
	temp->next = table;
}

t_philo	*build_philos(t_god **temp)
{
	t_philo	*bob;

	bob = malloc(sizeof(t_philo));
	bob->bobs_id = 0;
	bob->die = (*temp)->die;
	bob->sleep = (*temp)->sleep;
	bob->eat = (*temp)->eat;
	bob->eating_amount = (*temp)->eating_amount;
	bob->table = (*temp)->table;
	return (bob);
}

void	build_table(t_god **data, int i)
{
	t_table	*new;
	t_table *temp;

	new = malloc(sizeof(t_table));
	if (!new)
		exit(write(2, "Error\n", 6));
	new->id = i;
	temp = (*data)->table;
	if (temp)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
	else
	{
		new->next = NULL;
		(*data)->table = new;
	}
}

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
	temp->table = NULL;
	int		i;

	i = 0;
	check_args(argc, argv);
	basic_data(&temp, argc, argv);
	while (i != temp->philo)
	{
		temp->philos[i] = build_philos(&temp);
		temp->philos[i]->bobs_id = i;
		build_table(&temp, i);
		// printf("bobs_id = %d\n", temp->philos[i]->bobs_id);
		i++;
	}
	make_round(temp->table);
	return(temp);
}