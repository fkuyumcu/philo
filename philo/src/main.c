/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/08 16:45:35 by fkuyumcu         ###   ########.fr       */
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






