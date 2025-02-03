/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:47:17 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/03 13:27:38 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = current_time_in_ms();
	while ((current_time_in_ms() - start) < milliseconds)
		usleep(500);//microsaniye cinsinden argüman alır
	return (0);
}

void ferror(char *s)
{
	//TODO	

    return (0);
}

long current_time_in_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

