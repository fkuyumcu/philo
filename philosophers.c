/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/02 17:27:33 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_rules *rules;
    if(check_args(argc,argv))
    {
        f_init(argc, argv, rules);
		create_philos(rules);
		if(start_dinner(rules))
			ferror("Error");
    }
    else 
    {
        ferror("Wrong Input.\n Correct is"
        " ./philo 5 100 234 233 [2] ");
    }
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
	
	/*
	if (p->check_meal && philo[p->num - 1].iter_num == p->max_iter)
	{
		ft_usleep(5 * p->num);
		printf("						\n");
		printf("  All philosophers have eaten %d times\n", p->max_iter);
		return (final_print(1));
	}
	return (final_print(0));
	*/
	
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

void nietzche(t_rules *rules)
{
	//TODO
}

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







