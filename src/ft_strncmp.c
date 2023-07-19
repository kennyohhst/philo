/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/19 16:25:41 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;
	size_t			i;
	int				c;

	one = (unsigned char *) s1;
	two = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (one[i] == '\0' && two[i] == '\0')
			return (0);
		if (one[i] != two[i])
			return (c = (one[i] - two[i]));
		i++;
	}
	return (0);
}
