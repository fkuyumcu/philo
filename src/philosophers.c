/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:21:32 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/07 12:52:23 by fkuyumcu         ###   ########.fr       */
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
	//pthread_mutex_lock(rules->aaa_mutex);
	rules->is_ready = 1;
	//pthread_mutex_unlock(rules->aaa_mutex);
}	



int	start_dinner(t_rules *rules)
{
	int i;
	
	i = -1;
	
	if (rules->num_meals == 0 && rules->check_meal == 1)
		return 0;
	if(rules->num_philo == 1)
		nietzche(rules);
	else if(rules->num_philo > 1)
	{
		while (++i < rules->num_philo)
		{
			
			if(pthread_create(&rules->philos[i].thread_id, NULL, routine, &rules->philos[i]))
				return (1);
		}
	}
	return 0;
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
	pthread_mutex_destroy(rules->forks);
	pthread_mutex_destroy(rules->rand_mutex);
	pthread_mutex_destroy(rules->start_mutex);
	pthread_mutex_destroy(rules->furky_mutex);
	//pthread_mutex_destroy(rules->aaa_mutex);
	free(rules->forks);
	free(rules->print_mutex);
	free(rules->philos);
	free(rules->rand_mutex);
	free(rules->start_mutex);
	free(rules->furky_mutex);
	//free(rules->aaa_mutex);
}