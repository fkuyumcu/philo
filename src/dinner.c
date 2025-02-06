/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:26:50 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/06 19:37:41 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_philo *philo)
{
    t_rules	*rules;

    rules = philo->data;
    fork_lock(philo);
    philo_print(philo, "is eating");
	//pthread_mutex_lock(philo->data->rand_mutex);
    //philo->last_meal = current_time_in_ms();
   // pthread_mutex_unlock(philo->data->rand_mutex);
    ft_usleep(rules->time_eat);
	
	pthread_mutex_lock(philo->data->rand_mutex);
    philo->meals_eaten++;
	philo->data->ate++;
	pthread_mutex_unlock(philo->data->rand_mutex);
	
	fork_unlock(philo);
}

void fork_lock(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->left_fork);
        philo_print(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        philo_print(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        philo_print(philo, "has taken a fork");
        pthread_mutex_lock(philo->left_fork);
        philo_print(philo, "has taken a fork");
    }
}

void fork_unlock(t_philo *philo)
{
    if (philo->id % 2 == 0)
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
	
	while (!(philo->data->is_ready))
		continue ;
	
	pthread_mutex_lock(philo->data->start_mutex);
	if(philo->data->ate == 0)
		philo->data->start_time = current_time_in_ms();
	pthread_mutex_unlock(philo->data->start_mutex);
		
	 while (!philo->data->is_finish)
	{
		eat(philo);
		lazyness(philo);
	} 
	return (NULL);
}
void philo_print(t_philo *philo, char *action)
{
    t_rules *rules;

    pthread_mutex_lock(philo->data->print_mutex);
    rules = philo->data;

    if (rules->is_finish && ft_strncmp(action, "died", 5))
    {
        pthread_mutex_unlock(rules->print_mutex);
        return;
    }

    printf("%ld %d %s\n", current_time_in_ms() - philo->data->start_time,
           philo->id, action);

    pthread_mutex_unlock(philo->data->print_mutex);
}