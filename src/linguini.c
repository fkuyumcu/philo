/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linguini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:26:50 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/02 19:29:58 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *p)
{
    /*
    Burada mutexler ve tek-çift sayı algoritmaları bulunacak
     */
    
}

void    lazyness(t_philo *philo)//sleep and think
{
    ft_usleep(philo->data->time_sleep);
	print_routine(philo, SLEEP);
	print_routine(philo, THINK);
}