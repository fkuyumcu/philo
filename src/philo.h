/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:19 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/07 18:55:16 by fkuyumcu         ###   ########.fr       */
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
	int				ate;
	int				is_full;
	int				is_finish;//bir filozof öldüğünde ya da hepsi doyduğunda bu flag 1 olur.
	t_mutex			*forks;
	t_mutex			*print_mutex;
	//t_mutex			*aaa_mutex;
	t_mutex			*meal_mutex;
	//t_mutex			*furky_mutex;
	t_mutex			*finish_mutex;
	long			start_time;
	t_philo			*philos;
	
} t_rules;

int		check_args(int argc, char **argv);//OK
int		check_death(t_philo *philo);//TODO
int		check_meals(t_philo philo, int meal);//TODO
void	check_philos(t_rules *rules);//OK


int		ft_atoi(const char *str);//could ve converted to atol
int		ft_isdigit(int c);//OK
int		ft_isnum(char *str);//OK
int		ft_strlen(const char *str);//OK
int		ft_usleep(size_t milliseconds);//OK
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		start_dinner(t_rules *rules);
void	final_log(int is_alive);

void	philo_print(t_philo *philo, char *action);//TODO
void	fork_lock(t_philo *philo);
void	fork_unlock(t_philo *philo);
void	end_philos(t_rules *rules);
void	philo_error(char *s, t_rules *rules, t_philo *philo, int malloc);

void    lazyness(t_philo *philo);
void	eat(t_philo *philo);


void	nietzche(t_rules *rules);//TODO

void	philo_init(t_rules *rules);//OK
void	create_philos(t_rules *rules);//OK

void	init(char **argv, int argc, t_rules *rules);
void	*routine(void *job);

long	current_time_in_ms(void);






#endif