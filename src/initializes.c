/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:42:56 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/06 16:26:59 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_init(t_rules *rules)
{
	int 	i;
	t_philo	*philo;

	i = -1;
	while(++i < rules->num_philo)
	{
		philo = rules->philos + i;	
        philo->last_meal = current_time_in_ms();
		philo->id = i + 1;
		philo->is_full = 0;
		philo->meals_eaten = 0;
		philo->data = rules;
		rules->philos[i].left_fork = &rules->forks[i];
		rules->philos[i].right_fork = &rules->forks[(i + 1) % (rules->num_philo)];//!!!!!!!
	}
}

void init(char **argv, int argc, t_rules *rules)
{

    rules->num_philo = ft_atoi(argv[1]);
	rules->time_die  = ft_atoi(argv[2]);
    rules->time_eat  = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if(argc == 6)
    {
		rules->num_meals = ft_atoi(argv[5]);
        rules->check_meal = 1;
    }
	else
		rules->check_meal = 0;
	rules->forks = malloc(sizeof(t_mutex) * rules->num_philo);
	rules->philos = malloc(sizeof(t_philo) * rules ->num_philo);
	rules->print_mutex = malloc(sizeof(t_mutex) * 5);
	rules->is_finish = 0;
    rules->is_ready = 0;
	rules->ate = 0;
	pthread_mutex_init(rules->print_mutex, NULL);
}