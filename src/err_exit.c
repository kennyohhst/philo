/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:23:50 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/11 18:48:14 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	err_exit(int i, void *data)
{
	const char	err_msg[13][26] = {
		"0_parse_func\n", 
		"1_check_args_func\n",
		"2_num_check_func_1\n",
		"3_add_philo_func\n",
		"4_add_death_func\n",
		"5_add_eat_func\n",
		"6_add_sleep_func\n",
		"7_add_eating_amount_func\n",
		"8_build_philo_func\n",
		"9_build_table_func\n",
		"10_make_round_func\n",
	};

	(void) data;
	if (i < 0)
		return (0);
	else
	{
		free(data);
		write(STDERR_FILENO, "Error:	", 8);
		write(STDERR_FILENO, err_msg[i], sizeof(err_msg[i]));
		return (i);
	}
}
