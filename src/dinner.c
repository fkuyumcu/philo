/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:26:50 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/04 18:43:42 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_philo *philo)
{
    t_rules	*rules;

    rules = philo->data;
    fork_lock(philo);
    philo->last_meal = current_time_in_ms();
    philo_print(philo, "is eating");
    ft_usleep(rules->time_eat);
    philo->meals_eaten++;
	fork_unlock(philo);
}

void	fork_lock(t_philo *philo)
{
	if ((philo->id) % 2 == 0)
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
    if ((philo->id) % 2 == 0)
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

void    lazyness(t_philo *philo)//sleep and think
{
    philo_print(philo, "is sleeping");
    ft_usleep(philo->data->time_sleep);
	philo_print(philo, "is thinking");
}

void *routine(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	while (!philo->data->is_ready)
		continue ;
	/* if (philo->id & 1) tek-çift sayı beklemesi
		ft_usleep(philo->data->time_eat * 0.9 + 1); */
	 while (!philo->data->is_finish)//segfault
	{
		eat(philo);
		//lazyness(philo);
	} 
	return (NULL);
}

void	philo_print(t_philo *philo, char *action)
{
	t_rules *rules;
	rules = philo->data;
	pthread_mutex_lock(rules->print_mutex);
	if (rules->is_finish)
	{
		pthread_mutex_unlock(rules->print_mutex);
		return ;
	}
	printf("%ldms %d %s\n", current_time_in_ms() - philo->data->start_time,//-----------
		philo->id, action);
	pthread_mutex_unlock(philo->data->print_mutex);
} 