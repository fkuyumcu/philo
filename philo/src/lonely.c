/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:15:25 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/10 12:30:13 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*loop(void *arg)
{
	t_rules			*rules;
	pthread_mutex_t	fork;

	rules = (t_rules *)arg;
	pthread_mutex_init(&fork, NULL);
	rules->start_time = current_time();
	pthread_mutex_lock(&fork);
	printf("0 1 has taken a fork\n");
	printf("0 1 is thinking\n");
	ft_usleep(rules->time_die);
	printf("%d 1 died\n", rules->time_die);
	return (NULL);
}

void	nietzsche(t_rules *rules)
{
	pthread_t	m1;

	if (pthread_create(&m1, NULL, loop, rules) != 0)
		return (philo_error(rules));
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
	int	i;

	if (argc == 5 || argc == 6)
	{
		i = 1;
		while (argv[i])
		{
			if (!(ft_isnum(argv[i])))
				return (0);
			else if (ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) >= 2147483647)
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

void	philo_print(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->data->finish_mutex);
	if (philo->data->is_finish && ft_strncmp(action, "died", 5))
	{
		pthread_mutex_unlock(philo->data->finish_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->data->finish_mutex);
	pthread_mutex_lock(philo->data->print_mutex);
	printf("%ld %d %s\n", current_time() - philo->data->start_time,
		philo->id, action);
	pthread_mutex_unlock(philo->data->print_mutex);
}
