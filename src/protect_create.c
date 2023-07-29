/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:50:59 by code              #+#    #+#             */
/*   Updated: 2023/07/29 02:59:08 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*protect_create(t_god *data)
{
	pthread_mutex_lock(&data->blood_check);
	data->bobs_blood = true;
	pthread_mutex_unlock(&data->blood_check);
	pthread_mutex_unlock(&data->start);	
	return (NULL);
}
