/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/01 19:18:21 by fkuyumcu         ###   ########.fr       */
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
        //program ne zaman sonlanmalı-> 1 filozof ölürse ya da maksimum öğün sayısı geçilirse        
    }
    else 
    {
        ferror("Wrong Input.\n Correct is"
        " ./philo 5 100 234 233 [2] ");
    }
}

void 	create_philos(t_rules *rules)
{
	int i;
	int num;
	num = rules->num_philo;
	i = 0;//!!!!!!
	while(i < num)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	i = 0;
	while(i < num)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].left_fork = &rules->forks[i];
		rules->philos[i].right_fork = &rules->forks[(i + 1) % rules->num_philo];
		rules->philos[i].meals_eaten = 0;
		rules->philos[i].data = rules;
		pthread_create(&rules->philos[i].thread_id, NULL, routine, &rules->philos[i]);
		i++;	
	}
	i = 0;
	while(i < num)
	{
		pthread_join(rules->philos[i].thread_id, NULL);
		i++;
	}
}

void routine(t_philo *philo)
{
	t_rules *rules = philo->data;


	
}


void f_init(int argc, char **argv, t_rules *rules)
{
    //argv'deki bütün değerleri rule structında ilgili yerlere ataycaağım
    //time_to_die = time_to_eat + time_to_sleep + 10
    rules->num_philo = ft_atoi(argv[1]);
	rules->time_die  = ft_atoi(argv[2]);
    rules->time_eat  = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if(argv[5])
		rules->num_meals = ft_atoi(argv[5]);
	else
		rules->num_meals = -1;
	rules->forks = malloc(sizeof(t_mutex) * rules->num_philo);
	rules->philos = malloc(sizeof(t_philo) * rules ->num_philo);
    rules->start_time = current_time_in_ms(); 
	rules->is_finish = 0;
}

long current_time_in_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

void ferror(char *s)
{
	//TODO	

    return (0);
}
