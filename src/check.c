/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:40:11 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/05 03:47:27 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int funeral(t_philo *philo)
{
	philo->is_died = 1;
	philo->data->is_finish = 1;
	philo_print(philo,"died");
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);	
}

int		check_death(t_philo *philo)
{
    size_t hunger;
    pthread_mutex_lock(philo->data->print_mutex);
    hunger = current_time_in_ms() - philo->last_meal;
    if(hunger >= philo->data->time_die)
    {
        philo->data->is_finish = 1;
        pthread_mutex_unlock(philo->data->print_mutex);
		funeral(philo);
        return(1);
    }
    pthread_mutex_unlock(philo->data->print_mutex);
    return (0);
}

int check_meals(t_philo philo, int meal)
{
    int i;
    t_rules *rules;

    rules = philo.data;
    i = -1;
    if(rules->check_meal == 1)
    {
        while (++i < rules->num_philo)
        {
            if (rules->philos[i].meals_eaten < meal)
                return (1);
        }
    rules->is_finish = 1;
    }
    return (0);
}

void		final_log(int is_alive)
{
    if(is_alive)
        printf("\nEverybody is OK :)");
    else
        printf("\nDeath is God's will Huseyin brother :(\n");
}