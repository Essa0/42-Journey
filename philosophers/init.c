/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 03:00:00 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/05/10 00:51:03 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_philo_info *info)
{
	if (pthread_mutex_init(&info->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&info->dead_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&info->print_mutex);
		return (1);
	}
	if (pthread_mutex_init(&info->meal_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&info->print_mutex);
		pthread_mutex_destroy(&info->dead_mutex);
		return (1);
	}
	return (0);
}

void	cleanup_all(t_philo_info *info)
{
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->dead_mutex);
	pthread_mutex_destroy(&info->meal_mutex);
}

int	init_table(t_philo_info *info)
{
	int	i;

	if (init_mutex(info) != 0)
		return (1);
	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->fork_mutex)
	{
		cleanup_all(info);
		return (1);
	}
	info->is_dead = 0;
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork_mutex[i], NULL) != 0)
		{
			free_fork(info, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philo(t_philo **philo, t_philo_info *info)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * info->num_philo);
	if (!(*philo))
		return (1);
	i = 0;
	while (i < info->num_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].info = info;
		(*philo)[i].last_time_eat = 0;
		(*philo)[i].num_meals_eaten = 0;
		(*philo)[i].l_fork = &info->fork_mutex[i];
		(*philo)[i].r_fork = &info->fork_mutex[(i + 1) % info->num_philo];
		i++;
	}
	return (0);
}
