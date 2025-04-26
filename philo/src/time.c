/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:47:17 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/10 12:29:48 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = current_time();
	while ((current_time() - start) < milliseconds)
		usleep(100);
	return (0);
}

void	philo_error(t_rules *rules)
{
	if (rules->forks)
		free(rules->forks);
	if (rules->print_mutex)
		free(rules->print_mutex);
	if (rules->meal_mutex)
		free(rules->meal_mutex);
	if (rules->finish_mutex)
		free(rules->finish_mutex);
	if (rules->philos)
		free(rules->philos);
}

long int	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
