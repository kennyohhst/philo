/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:41:30 by code              #+#    #+#             */
/*   Updated: 2023/07/30 15:23:15 by code             ###   ########.fr       */
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
	struct s_table	*next;
	struct s_table	*prev;
	pthread_mutex_t	l_fork;
}	t_table;

typedef struct philos
{
	int				bobs_id;
	int				eating_amount;
	int				fork;
	long			eat;
	long			sleep;
	long			die;
	t_table			*table;
	pthread_t		philo;
	struct s_god	*god;
	unsigned long	last_food;
	pthread_mutex_t	nomnom;
}	t_philo;

typedef struct s_god
{
	int				philo;
	int				die;
	int				sleep;
	int				eat;
	int				eating_amount;
	bool			bobs_blood;
	bool			fifth_arg;
	t_philo			*philos[200];
	t_table			*table;
	pthread_t		check_death;
	unsigned long	start_time;
	pthread_mutex_t	death;
	pthread_mutex_t	msg;
	pthread_mutex_t	blood_check;
	pthread_mutex_t	start;
}	t_god;


//	PARSING ALL THAT BEAUTIFULL CODE
t_god			*parse(int argc, char **argv);
int					check_args(int argc, char **argv);
int						ft_numcheck(char *str);
//		PUT DATA INTO GOD
int					basic_data(t_god **temp, int argc, char **argv);
int						add_philos(t_god **temp, char *num);
int						add_death(t_god **temp, char *num);
int						add_eating_amount(t_god **temp, char *num);
int						add_sleep(t_god **temp, char *num);
int						add_eat(t_god **temp, char *num);
int							ft_atoi(const char *str);
long						ft_atoi_l(const char *str);
//		PUT DATA INTO PHILO
t_philo				*build_philos(t_god **temp);
//		PUT DATA INTO TABLES
int					build_table(t_god **data, int i);
//		CIRCULAR LINKED LIST 
int					make_round(t_god *data);
//		EXIT CODES
int					err_exit(int i, void *data);
//		INITIALIZE GODS MUTEXES
void			init_mutex(t_god *data);

//	START THE SIM AND MAKE IT GO BRRRR
long			start_sim(t_god *data);
//		EACH PHILO USES LIFE
void				*life(void *philo);
//			THEY GRAB A FORK, EAT, SLEEP AND THINK
void					grab_fork(t_philo **philo);
void					eat_sleep_think(t_philo *philo);
//				AND THEN GET MORE TIME TO LIVE
void						new_time_eat(t_philo *bob);
//		DEATH WILL WATCH THEM DIE AND ALART ALL PHILO'S
void				*death(void *god);
//		IF ANY THREAD FAILS, SET BOBS_BLOOD TO TRUE
void				*protect_create(t_god *data);
//	FREE ALL AND EXIT CLEAN
void			freelosopher(t_god *data);

//	PRINT MESSAGE
void				printf_msg(t_god *god, char *str, int i, unsigned long c_t);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
//	IF BOBS SINGLE, THIS WILL RUN AND END THE PROGRAM
void				bobs_single(t_philo *bob);
//	BETTER USLEEP SOMEHOW
void				ft_usleep(unsigned long time);
//	RETURNS CURRENT TIME
unsigned long		ft_time(void);
//	IF ANYONE DIES, THIS SHOULD CATCH IT
int					ft_stop(t_god *data);


#endif
