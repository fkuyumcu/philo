/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:47:17 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/08 15:31:00 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = current_time_in_ms();
	while ((current_time_in_ms() - start) < milliseconds)
		usleep(100);
	return (0);
}

void philo_error(t_mutex *forks, t_mutex *print, t_mutex *meal,
 t_mutex *finish, t_philo *philos)
{
	if (forks)
        free(forks);
    if (print)
        free(print);
    if (meal)
        free(meal);
    if (finish)
        free(finish);
    if (philos)
        free(philos);
}

long int current_time_in_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

