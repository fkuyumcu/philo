/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:47:17 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/10 11:39:56 by fkuyumcu         ###   ########.fr       */
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

long int	current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
