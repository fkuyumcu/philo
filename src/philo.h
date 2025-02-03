/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:19 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/02/03 13:41:26 by fkuyumcu         ###   ########.fr       */
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

int		check_args(int argc, char **argv);
void	ferror(char *s);//TODO
int		ft_atoi(const char *str);//could be converted to atol
int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_strlen(const char *str);
void	f_init(int argc, char **argv, t_rules *rules);
void	create_philos(t_rules *rules);
int		ft_usleep(size_t milliseconds);
void	philo_init(t_rules *rules);
int		start_dinner(t_rules *rules);
void	nietzche(t_rules *rules);//ad hoc
void	eat(t_philo *p);
void    lazyness(t_philo *p);
int		final_log(int is_alive);
long	current_time_in_ms(void);
void	philo_print(t_philo *philo, char *action);//TODO
void	fork_lock(t_philo *philo);
void	fork_unlock(t_philo *philo);

typedef pthread_mutex_t t_mutex;

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


#endif