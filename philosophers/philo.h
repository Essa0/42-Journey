/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:56:51 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/02/26 18:00:23 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR_MSG "Error: invalid arguments\n"

/*
	** structs:
		- philo_info: shared info for all 
		- philo: individual philosopher data
*/

typedef struct s_philo_info
{
	int					num_philo;
	int					is_dead;
	int					must_eat;
	long long			start_time;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		*fork_mutex;
}				t_philo_info;

typedef struct s_philo
{
	int				id;
	int				num_meals_eaten;
	long long		last_time_eat;
	pthread_t		th;
	t_philo_info	*info;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}				t_philo;

/* utils.c */
long long	get_time(void);
void		ft_usleep(long long ms);
void		print_fun(t_philo *philo, char *str);
int			died_alert(t_philo *philo, int check);
int			free_fork(t_philo_info *info, int n);

/* init.c */
int			init_table(t_philo_info *info);
int			init_philo(t_philo **philo, t_philo_info *info);

/* routine.c */
void		*routine_philo(void *arg);

/* waiter.c */
int			waiter(t_philo *philo);

/* main.c */
int			validate_and_parse(int ac, char **av, t_philo_info *info);
int			create_philo(t_philo_info *info, t_philo *philo);

#endif