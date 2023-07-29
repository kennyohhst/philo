/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:22:01 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/29 02:26:24 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_mutex(t_god *data)
{
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(&data->blood_check, NULL);
	pthread_mutex_init(&data->start, NULL);
	
}
