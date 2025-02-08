/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:40:11 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/08 15:52:06 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int funeral(t_philo *philo)
{
    philo_print(philo,"died");
	return (1);	
}

int check_death(t_philo *philo)
{
    int hunger;

    pthread_mutex_lock(philo->data->meal_mutex);
    hunger = current_time_in_ms() - philo->last_meal;
    pthread_mutex_unlock(philo->data->meal_mutex);

    pthread_mutex_lock(philo->data->finish_mutex);
    if (philo->data->is_finish)
    {
        pthread_mutex_unlock(philo->data->finish_mutex);
        return (0);
    }
    pthread_mutex_unlock(philo->data->finish_mutex);
    if (hunger > philo->data->time_die)
    {
        pthread_mutex_lock(philo->data->finish_mutex);
        philo->data->is_finish = 1;
        pthread_mutex_unlock(philo->data->finish_mutex);
        return (funeral(philo));
    }
    return (0);
}

int check_meals(t_philo philo, int meal)
{
    int i;
    t_rules *rules;

    rules = philo.data;
    i = -1;
    if (rules->check_meal == 1)
    {
        pthread_mutex_lock(rules->meal_mutex);
        while (++i < rules->num_philo)
        {
            if (rules->philos[i].meals_eaten < meal)
            {
                pthread_mutex_unlock(rules->meal_mutex);
                return (1);
            }
        }
        pthread_mutex_unlock(rules->meal_mutex);
        pthread_mutex_lock(rules->finish_mutex);
        rules->is_finish = 1;
        pthread_mutex_unlock(rules->finish_mutex);
    }
    return (0);
}

void	check_philos(t_rules *rules)
{
	int i;
	t_philo *philo;

	philo = rules->philos;
	
	while(!rules->is_ready)
		continue;
	while(!rules->is_finish)
	{
		i = -1;
		while(++i < rules->num_philo)
		{
			if (check_death(&philo[i]) || check_meals(philo[i], rules->num_meals))
				break ;
		}
	}
}