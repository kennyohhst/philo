/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:54:31 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/14 21:34:16 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	make_round(t_god *data)
{
	t_table	*temp;
	int		i;

	i = 0;
	temp = data->table;
	while (temp->next != NULL)
	{
		temp->l_fork = malloc(sizeof(pthread_mutex_t));
		if (!temp->l_fork)
			return (0);
		pthread_mutex_init(temp->l_fork, NULL);
		data->philos[i++]->table = temp;
		temp = temp->next;
	}
	temp->l_fork = malloc(sizeof(pthread_mutex_t));
	if (!temp->l_fork)
		return (0);
	pthread_mutex_init(temp->l_fork, NULL);
	data->philos[i++]->table = temp;
	temp->next = data->table;
	temp->next->l_fork = data->table->l_fork;
	return (1);
}

t_philo	*build_philos(t_god **temp)
{
	t_philo	*bob;

	bob = malloc(sizeof(t_philo));
	if (!bob)
		return (NULL);
	bob->time_bob = malloc(sizeof(pthread_mutex_t));
	bob->god = (*temp);
	bob->bobs_id = 0;
	bob->total_philos = (*temp)->philo;
	bob->die = (*temp)->die * 1000;
	bob->sleep = (*temp)->sleep * 1000;
	bob->eat = (*temp)->eat * 1000;
	bob->eating_amount = (*temp)->eating_amount;
	bob->table = (*temp)->table;
	return (bob);
}

int	build_table(t_god **data, int i)
{
	t_table	*new;
	t_table	*temp;

	new = malloc(sizeof(t_table));
	if (!new)
		return (0);
	new->id = i;
	new->grab = false;
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
	return (1);
}

int	basic_data(t_god **temp, int argc, char **argv)
{
	(*temp)->death = malloc(sizeof(pthread_mutex_t));
	if (add_philos(temp, argv[1]))
		return (add_philos(temp, argv[1]));
	if (add_death(temp, argv[2]))
		return (add_death(temp, argv[2]));
	if (add_eat(temp, argv[3]))
		return (add_eat(temp, argv[3]));
	if (add_sleep(temp, argv[4]))
		return (add_sleep(temp, argv[4]));
	if (argc == 6)
	{
		if (add_eating_amount(temp, argv[5]))
			return (add_eating_amount(temp, argv[5]));
	}
	(*temp)->msg = malloc(sizeof(pthread_mutex_t));
	(*temp)->time = malloc(sizeof(pthread_mutex_t));
	return (0);
}

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
