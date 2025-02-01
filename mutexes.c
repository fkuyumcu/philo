/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:22:00 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/01 14:22:24 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    mutex_left(t_philo *philo)
{
    pthread_mutex_t *mut = philo->left_fork;
}

void    mutex_right(t_philo *philo)
{
    
}