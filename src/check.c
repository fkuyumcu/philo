/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:40:11 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/07 12:58:30 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int funeral(t_philo *philo)
{
    philo_print(philo,"died");
	philo->is_died = 1;
    pthread_mutex_lock(philo->data->furky_mutex);
	philo->data->is_finish = 1;
    pthread_mutex_unlock(philo->data->furky_mutex);
    
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);	
}

int		check_death(t_philo *philo)
{
    int hunger;
    
    pthread_mutex_lock(philo->data->print_mutex);
    hunger = current_time_in_ms() - philo->last_meal;
    if(hunger > philo->data->time_die)
    {
        pthread_mutex_lock(philo->data->furky_mutex);
        philo->data->is_finish = 1;
        pthread_mutex_unlock(philo->data->furky_mutex);
        pthread_mutex_unlock(philo->data->print_mutex);
        return(funeral(philo));
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
    pthread_mutex_lock(philo.data->furky_mutex);
    rules->is_finish = 1;
    rules->is_full = 1;
    pthread_mutex_unlock(philo.data->furky_mutex);
    }
    return (0);
}

void		final_log(int is_alive)
{
    if(is_alive)
        printf("\nEverybody is OK :)");
    else
        printf("\nSomeone's Dead :(\n");
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
			if (check_death(&philo[i]) || check_meals(philo[i], rules->num_meals))//birisi doyduysa ya da öldüyse 1 döndürecek
				break ;
		}
	}
	if (rules->check_meal && rules->is_full == 1)
	{
		ft_usleep(5 * rules->num_philo);
		printf("						\n");
		printf("  All philosophers have eaten %d times\n", rules->num_meals);
		final_log(1);
		return ;
	}
	final_log(0);
}