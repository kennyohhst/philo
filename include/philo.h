/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:41:30 by code              #+#    #+#             */
/*   Updated: 2023/07/21 18:04:51 by kkalika          ###   ########.fr       */
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
	struct s_table	*prev;
}t_table;

typedef struct philos
{
	long			last_food;
	int				bobs_id;
	long			eat;	
	long			sleep;
	int				eating_amount;
	long			die;
	int				fork;
	// bool			stop;
	t_table			*table;
	pthread_t		philo;
	pthread_mutex_t nomnom;
	struct s_god	*god;
	
}t_philo;

typedef struct s_god
{
	int				philo;
	int				die;
	int				sleep;
	int				eat;
	int				eating_amount;
	bool			bobs_blood;
	bool			fifth_arg;
	long			start_time;
	long			death_stamp;
	t_philo			*philos[200];
	t_table			*table;
	pthread_t		check_death;
	pthread_mutex_t	*death;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*time;
}t_god;

int		eat_sleep_think(t_philo *philo);
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
void	*death(void *god);
void	set_time(t_philo *bob);
void	new_time_eat(t_philo *bob);
void	new_time_sleep(t_philo *bob);
void	new_time_die(t_philo *bob);
void	freelosopher(t_god *data);
void	printf_msg(t_god *god, char *str, int i, long stamp);
void	init_mutex(t_god *data);
int		ft_stop(t_philo *philo);
int		basic_data(t_god **temp, int argc, char **argv);
int		build_table(t_god **data, int i);
t_philo	*build_philos(t_god **temp);
int		make_round(t_god *data);
bool	grab_fork_fork(t_table *chair);
int		grab_fork(t_philo **philo);
void	drop_fork_fork(t_table *chair);
void	ft_usleep(long time);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*life(void *philo);
void	*bobs_single(t_philo *bob);

#endif
