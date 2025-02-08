/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:21:32 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/08 15:41:08 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void 	create_philos(t_rules *rules)
{
	int i;
	int num;
	num = rules->num_philo;
	i = 0;
	while(i < num)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	philo_init(rules);
	rules->is_ready = 1;
}	

void end_philos(t_rules *rules)
{
	int i;
	t_philo *philo;

	philo = rules->philos;
	i = -1;
	while (++i < rules->num_philo)
			pthread_join(rules->philos[i].thread_id, (void *)&philo[i]);
	pthread_mutex_destroy(rules->print_mutex);
	pthread_mutex_destroy(rules->finish_mutex);
	pthread_mutex_destroy(rules->forks);
	pthread_mutex_destroy(rules->meal_mutex);
	free(rules->forks);
	free(rules->print_mutex);
	free(rules->finish_mutex);
	free(rules->philos);
	free(rules->meal_mutex);
}