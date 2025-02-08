/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:19 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/08 15:27:29 by fkuyumcu         ###   ########.fr       */
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
	t_mutex			*meal_mutex;
	t_mutex			*finish_mutex;
	long			start_time;
	t_philo			*philos;
	
} t_rules;

int		check_args(int argc, char **argv);
int		check_death(t_philo *philo);
int		check_meals(t_philo philo, int meal);
void	check_philos(t_rules *rules);//OK


long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_strlen(const char *str);
int		ft_usleep(size_t milliseconds);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		start_dinner(t_rules *rules);

void	philo_print(t_philo *philo, char *action);
void	fork_lock(t_philo *philo);
void	fork_unlock(t_philo *philo);
void	end_philos(t_rules *rules);
void	philo_error(t_mutex *forks, t_mutex *print, t_mutex *meal, t_mutex *finish, t_philo *philos);

void    lazyness(t_philo *philo);
void	eat(t_philo *philo);


void nietzsche(t_rules *rules);

void	philo_init(t_rules *rules);//OK
void	create_philos(t_rules *rules);//OK

void	init(char **argv, int argc, t_rules *rules);
void	*routine(void *job);

long	current_time_in_ms(void);






#endif