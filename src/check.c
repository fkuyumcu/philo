/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:40:11 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/04 18:13:30 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		check_death(t_philo *philo)//TODO
{
    philo--;
    return 0;

    
}
int		check_meals(t_philo philo, int meal)
{
    t_philo philo2 = philo;
    meal++;
    return 0;    
} 

int		final_log(int is_alive)
{
    return is_alive;
    
}