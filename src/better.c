/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:47:17 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/05 08:38:57 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = current_time_in_ms();
	while ((current_time_in_ms() - start) < milliseconds)
		usleep(100);//microsaniye cinsinden argüman alır
	return (0);
}

void	philo_error(char *s, t_rules *rules, t_philo *philo, int malloc)
{
	if (malloc)
	{
		if (rules->print_mutex)
			free(rules->print_mutex);
		if (rules->forks)
			free(rules->forks);
		if (philo)
			free(philo);
	}
	printf("%s", s);

}

long int current_time_in_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

