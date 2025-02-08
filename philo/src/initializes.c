/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:42:56 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/08 17:37:35 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < rules->num_philo)
	{
		philo = rules->philos + i;
		philo->id = i + 1;
		philo->meals_eaten = 0;
		philo->is_ready = 0;
		philo->last_meal = 0;
		philo->data = rules;
		rules->is_finish = 0;
		rules->philos[i].left_fork = &rules->forks[i];
		rules->philos[i].right_fork = &rules->forks[(i + 1)
			% (rules->num_philo)];
	}
}

void	init_values(char **argv, int argc, t_rules *rules)
{
	rules->num_philo = ft_atol(argv[1]);
	rules->time_die = ft_atol(argv[2]);
	rules->time_eat = ft_atol(argv[3]);
	rules->time_sleep = ft_atol(argv[4]);
	if (argc == 6)
	{
		rules->num_meals = ft_atol(argv[5]);
		rules->check_meal = 1;
	}
	else
	{
		rules->num_meals = 0;
		rules->check_meal = 0;
	}
	rules->is_ready = 0;
	rules->is_finish = 0;
	rules->ate = 0;
	rules->start_time = 0;
}

void	init_mutexes(t_rules *rules)
{
	rules->philos = malloc(sizeof(t_philo) * rules->num_philo);
	rules->forks = malloc(sizeof(t_mutex) * rules->num_philo);
	rules->print_mutex = malloc(sizeof(t_mutex));
	rules->meal_mutex = malloc(sizeof(t_mutex));
	rules->finish_mutex = malloc(sizeof(t_mutex));
	if (!rules->forks || !rules->philos || !rules->print_mutex
		|| !rules->meal_mutex || !rules->finish_mutex)
	{
		philo_error(rules->forks, rules->print_mutex, rules->meal_mutex,
			rules->finish_mutex, rules->philos);
	}
	pthread_mutex_init(rules->print_mutex, NULL);
	pthread_mutex_init(rules->finish_mutex, NULL);
	pthread_mutex_init(rules->meal_mutex, NULL);
}

void	init(char **argv, int argc, t_rules *rules)
{
	init_values(argv, argc, rules);
	init_mutexes(rules);
}
