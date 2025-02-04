/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:19 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/04 11:57:26 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>//gettimeofday

typedef pthread_mutex_t t_mutex;
typedef struct s_rules t_rules;

typedef struct s_philo
{
    int             id;
	int				is_ready;
	int				is_full;
	int				is_died;
    t_mutex			*left_fork;
    t_mutex			*right_fork;
    long            last_meal;
    int             meals_eaten;
    t_rules          *data;
    pthread_t       thread_id;

} t_philo;

typedef struct s_rules
{
	int 			is_ready;
    int 			num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_meals;
	int				check_meal;
	int				is_finish;//bir filozof öldüğünde ya da hepsi doyduğunda bu flag 1 olur.
	t_mutex			*forks;
	t_mutex			*print_mutex;
	long			start_time;
	t_philo			*philos;
	
} t_rules;

int		check_args(int argc, char **argv);
int		check_death(t_philo *philo);//TODO
int		check_meals(t_philo philo, int meal);//TODO
int		ft_atoi(const char *str);//could be converted to atol
int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_strlen(const char *str);
int		ft_usleep(size_t milliseconds);
int		start_dinner(t_rules *rules);
int		final_log(int is_alive);
void	philo_print(t_philo *philo, char *action);//TODO
void	fork_lock(t_philo *philo);
void	fork_unlock(t_philo *philo);
void	check_philos(t_rules *rules);
void	end_philos(t_rules *rules);
void	philo_error(char *s, t_rules *rules, t_philo *philo, int malloc);
void    lazyness(t_philo *p);
void	eat(t_philo *p);
void	nietzche(t_rules *rules);//ad hoc
void	philo_init(t_rules *rules);
void	create_philos(t_rules *rules);
void	init(char **argv, t_rules *rules);
long	current_time_in_ms(void);






#endif