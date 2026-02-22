/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:00:06 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/02/22 00:01:09 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

#define ERR_MSG "please follow this rules to avoid any possible error =>\n{usage: ./philo num_of_philos, time_to_die, time_to_eat, time_to_sleep, [num_of_times_each_philos_must_eat]}\nto be notic the last arg not mandatory to enter ;)\n"

typedef struct s_philo_info
{
	int					num_philo;
	int					is_dead;
	int					must_eat;
	long				start_time;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	// long				time_each_philo_eat;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		*fork_mutex;
}				t_philo_info;

typedef struct s_philo
{
	int				id;
	int				num_meals_eaten;
	long			last_time_eat;
	pthread_t		th;
	t_philo_info	*info;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}			t_philo;