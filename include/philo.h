/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:41:30 by code              #+#    #+#             */
/*   Updated: 2023/07/13 20:41:33 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_table
{
	int				id;
	bool			grab;
	pthread_mutex_t	*l_fork;
	struct s_table	*next;
}t_table;

typedef struct philos
{
	long			total_philos;
	bool			dead;
	int				bobs_id;
	int				eat;	
	int				sleep;
	int				eating_amount;
	int				die;
	int				fork;
	t_table			*table;
	pthread_t		philo;
	long			start_time;
}t_philo;

typedef	struct s_god
{
	int			philo;
 	int			die;
	int			sleep;
	int			eat;
	int			eating_amount;
	t_philo		*philos[200];
	t_table		*table;
}t_god;



t_god	*parse(int argc, char **argv);
int		ft_atoi(const char *str);
long	ft_atoi_l(const char *str);
int		ft_numcheck(char *str);
int		add_philos(t_god **temp, char *num);
int		add_eating_amount(t_god **temp, char *num);
int		add_death(t_god **temp, char *num);
int		add_sleep(t_god **temp, char *num);
int		add_eat(t_god **temp, char *num);
void	start_sim(t_god *data);
int		err_exit(int i, void *data);
int		check_args(int argc, char **argv);
int		basic_data(t_god **temp, int argc, char **argv);
int		build_table(t_god **data, int i);
t_philo	*build_philos(t_god **temp);
int		make_round(t_god *data);
long	ft_time(void);
int		death(t_philo *philo);

















#endif
