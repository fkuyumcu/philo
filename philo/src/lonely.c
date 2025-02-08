/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:15:25 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/08 17:11:05 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *loop(void *arg)
{
    t_rules *rules = (t_rules *)arg;

    rules->start_time = current_time_in_ms();
    rules->ate = current_time_in_ms();
    while (1)
    {
        printf("%ld %d is eating\n", current_time_in_ms() - rules->start_time, 1);
        rules->ate = current_time_in_ms();
        ft_usleep(rules->time_eat);
        printf("%ld %d is sleeping\n", current_time_in_ms() - rules->start_time, 1);
        ft_usleep(rules->time_sleep);
        if (current_time_in_ms() - rules->ate > rules->time_die)
        {
            printf("%ld %d died\n", current_time_in_ms() - rules->start_time, 1);
            break;
        }
    }
    return NULL;
}

void nietzsche(t_rules *rules)
{
    pthread_t m1;
    

    if (pthread_create(&m1, NULL, loop, rules) != 0)
        return philo_error(rules->forks,rules->print_mutex,rules->meal_mutex,
        rules->finish_mutex,rules->philos);
    pthread_join(m1, NULL);
    pthread_mutex_destroy(rules->print_mutex);
	pthread_mutex_destroy(rules->finish_mutex);
	pthread_mutex_destroy(rules->forks);
	pthread_mutex_destroy(rules->meal_mutex);
    free(rules->forks);
	free(rules->print_mutex);
	free(rules->finish_mutex);
	free(rules->philos);
	free(rules->meal_mutex);
}

int	check_args(int argc, char **argv)
{
    if (argc == 5 || argc == 6)
    {
        int i;
        i = 1;
        while(argv[i])
        {
            if(!(ft_isnum(argv[i])))
                return (0);
			else if(ft_atol(argv[i]) <= 0 ||  ft_atol(argv[i]) >= 2147483647)
				return (0);
            i++;
        }
    }
    else
    {
        return (0);  
    }
    return (1);
}

void philo_print(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->data->finish_mutex);
	if (philo->data->is_finish && ft_strncmp(action, "died", 5))
	{
		pthread_mutex_unlock(philo->data->finish_mutex);
		return;
	}
	pthread_mutex_unlock(philo->data->finish_mutex);
	pthread_mutex_lock(philo->data->print_mutex);
	printf("%ld %d %s\n", current_time_in_ms() - philo->data->start_time,
		   philo->id, action);
	pthread_mutex_unlock(philo->data->print_mutex);
}