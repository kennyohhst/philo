/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:41:30 by code              #+#    #+#             */
/*   Updated: 2023/07/09 15:59:25 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>



typedef struct table
{
	int				philo_total;
	int				forks_total;
}t_table;

typedef struct philos
{
	pthread_mutex_t	*forks;
	int				eat;	
	int				sleep;
	int				eating_amount;
	int				die;
	t_table			*table;
	pthread_t		philo;
}t_philo;

typedef	struct s_god
{
	int			philo;
 	int			die;
	int			sleep;
	int			eat;
	int			eating_amount;
	t_table		*table;
}t_god;



t_god	*parse(int argc, char **argv);
int		ft_atoi(const char *str);
long	ft_atoi_l(const char *str);
void	ft_numcheck(char *str);
void	add_philos(t_god **temp, char *num);
void	add_eating_amount(t_god **temp, char *num);
void	add_death(t_god **temp, char *num);
void	add_sleep(t_god **temp, char *num);
void	add_eat(t_god **temp, char *num);







#endif
