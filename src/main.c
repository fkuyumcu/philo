/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/02 19:25:46 by fkuyumcu         ###   ########.fr       */
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



void nietzche(t_rules *rules)
{
	//TODO
}









