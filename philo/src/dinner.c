/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:26:50 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/10 11:43:58 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->data;
	fork_lock(philo);
	philo_print(philo, "is eating");
	pthread_mutex_lock(philo->data->meal_mutex);
	philo->last_meal = current_time();
	pthread_mutex_unlock(philo->data->meal_mutex);
	ft_usleep(rules->time_eat);
	pthread_mutex_lock(philo->data->meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->data->meal_mutex);
	fork_unlock(philo);
}

void	fork_lock(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		philo_print(philo, "has taken a fork");
	}
}

void	fork_unlock(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	lazyness(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	ft_usleep(philo->data->time_sleep);
	philo_print(philo, "is thinking");
}

int	start_dinner(t_rules *rules)
{
	int	i;

	i = -1;
	if (rules->num_meals == 0 && rules->check_meal == 1)
		return (0);
	rules->start_time = current_time();
	if (rules->num_philo == 1)
		nietzsche(rules);
	else if (rules->num_philo > 1)
	{
		while (++i < rules->num_philo)
		{
			if (pthread_create(&rules->philos[i].thread_id, NULL, routine,
					&rules->philos[i]))
				return (1);
		}
		check_philos(rules);
		end_philos(rules);
	}
	return (0);
}
