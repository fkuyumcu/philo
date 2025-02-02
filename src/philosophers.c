/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:21:32 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/02 19:23:27 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void 	create_philos(t_rules *rules)
{
	int i;
	int num;
	num = rules->num_philo;
	i = 0;
	while(i < num)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	philo_init(rules);
	rules->is_ready = 1;
}

void routine(void *job)
{
	t_philo	*p;

	p = (t_philo *)job;
	while (!p->data->is_ready)
		continue ;
	if (p->id & 1)
		ft_usleep(p->data->time_eat * 0.9 + 1);
	while (!p->data->is_finish)
	{
		eat(p);
		lazyness(p);
	}
	return (NULL);
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
			if (check_death(&philo[i]) || check_meals(philo[i], i))
				continue ;
	}
	
	if (rules->check_meal && philo[rules->num_philo - 1].meals_eaten == rules->num_meals)
	{
		ft_usleep(5 * rules->num_philo);
		printf("						\n");
		printf("  All philosophers have eaten %d times\n", rules->num_meals);
		return (final_log(1));
	}
	return (final_log(0));
	
}

int	start_dinner(t_rules *rules)
{
	int i;

	i = -1;
	if (rules->num_meals == 0)
		return ;
	else if(rules->num_philo == 1)
		nietzche(rules);
	else
	{
		while (++i < rules->num_philo)
		{
			if(pthread_create(&rules->philos[i].thread_id,NULL, routine, &rules->philos[i]))
				return (1);
		}
		i = -1;
		while (++i < rules->num_philo)
			pthread_join(&rules->philos[i].thread_id,NULL);
	}
}