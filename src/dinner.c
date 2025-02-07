/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:26:50 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/07 17:11:38 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_philo *philo)
{
    t_rules	*rules;
    rules = philo->data;
    fork_lock(philo);
    philo_print(philo, "is eating");
    philo->last_meal = current_time_in_ms();
    ft_usleep(rules->time_eat);
    philo->meals_eaten++;
	fork_unlock(philo);
}

void fork_lock(t_philo *philo)
{
        pthread_mutex_lock(philo->left_fork);
        philo_print(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        philo_print(philo, "has taken a fork");

}

void fork_unlock(t_philo *philo)
{

        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

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
	if (philo->id & 1)
		ft_usleep(philo->data->time_eat * 0.9 + 1);
	 while (!philo->data->is_finish)
	{
		eat(philo);
		lazyness(philo);
	} 
	return (NULL);
}
void philo_print(t_philo *philo, char *action)
{
    pthread_mutex_lock(philo->data->print_mutex);
    if (philo->data->is_finish && ft_strncmp(action, "died", 5))
    {
        pthread_mutex_unlock(philo->data->print_mutex);
        return;
    }
    printf("%ld %d %s\n", current_time_in_ms() - philo->data->start_time,
           philo->id, action);
    

    pthread_mutex_unlock(philo->data->print_mutex);
}


int	start_dinner(t_rules *rules)
{
	int i;
	
	i = -1;
	
	if (rules->num_meals == 0 && rules->check_meal == 1)
		return 0;
	rules->start_time = current_time_in_ms();
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