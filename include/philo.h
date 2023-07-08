/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:41:30 by code              #+#    #+#             */
/*   Updated: 2023/06/29 00:31:19 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H



typedef struct philo
{
	int				fork;
	int				die;
	int				eat;
	int				sleep;
	int				wait;
	struct philo	*next;
}t_philo;



# include <unistd.h>
# include <stdio.h>
# include <pthread.h>



#endif
