/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:41:30 by code              #+#    #+#             */
/*   Updated: 2023/07/08 19:56:28 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H



typedef struct table
{
	int				philo;
	int				die;
	int				eat;
	int				sleep;
	// pthread_t		*philos;
}t_table;

typedef	struct s_god
{
	int			philo;
 	int			die;
	int			sleep;
	int			eat;
	int			eating_amount;
	t_table		*table;
}t_god;



# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

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
