/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:42:56 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/02 17:02:16 by fkuyumcu         ###   ########.fr       */
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
        philo->last_meal = current_time_in_ms();
		philo = rules->philos + i;	
		philo->id = i + 1;
		philo->is_full = 0;
		philo->meals_eaten = 0;
		philo->data = rules;
		rules->philos[i].left_fork = &rules->forks[i];
		rules->philos[i].right_fork = &rules->forks[(i + 2) % rules->num_philo];
	}
}

void f_init(int argc, char **argv, t_rules *rules)
{
    rules->num_philo = ft_atoi(argv[1]);
	rules->time_die  = ft_atoi(argv[2]);
    rules->time_eat  = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if(argv[5])
		rules->num_meals = ft_atoi(argv[5]);
	else
		rules->num_meals = -1;
	rules->forks = malloc(sizeof(t_mutex) * rules->num_philo);
    if(!rules->forks)
        ferror("Malloc Err");
	rules->philos = malloc(sizeof(t_philo) * rules ->num_philo);
    if(!rules->forks)  
        ferror("Malloc Err");
    rules->start_time = current_time_in_ms(); 
	rules->is_finish = 0;
}