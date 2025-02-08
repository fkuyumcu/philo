/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/08 17:11:50 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)//hata durumlarına bak
{
    t_rules rules;
    
    if(check_args(argc,argv))
    {
        init(argv, argc, &rules);
		create_philos(&rules);
		start_dinner(&rules);
        return (0);
    }
    else 
        printf("Error\n");
    return (1);
}

void *routine(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	while (!(philo->data->is_ready))
		continue ;
	 while (1)
	{
		if(philo->id % 2 == 0)
		{
			eat(philo);
			lazyness(philo);
		}
		else
		{
			lazyness(philo);
			eat(philo);
		}
	pthread_mutex_lock(philo->data->finish_mutex);
	int is_finish = philo->data->is_finish;
	pthread_mutex_unlock(philo->data->finish_mutex);
	if (is_finish)
		break;
}
	return (NULL);
}





