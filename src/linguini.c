/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linguini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:26:50 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/03 13:42:35 by fkuyumcu         ###   ########.fr       */
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
		ft_usleep(5);
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
    ft_usleep(philo->data->time_sleep);
	philo_print(philo, "is sleeping");
	philo_print(philo, "is thinking");
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
	printf("%ldms %d %s\n", time_now() - philo->thread_start,
		p->id, action);
	pthread_mutex_unlock(p->par->print_mutex);
}