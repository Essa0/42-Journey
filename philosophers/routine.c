/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:53:56 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/02/26 17:59:17 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_fun(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_fun(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
	}
	print_fun(philo, "has taken a fork");
}

static void	philo_eat(t_philo *philo)
{
	print_fun(philo, "is eating");
	pthread_mutex_lock(&philo->info->meal_mutex);
	philo->last_time_eat = get_time();
	philo->num_meals_eaten++;
	pthread_mutex_unlock(&philo->info->meal_mutex);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	philo_think(t_philo *philo)
{
	print_fun(philo, "is thinking");
	if (philo->info->num_philo % 2 == 1)
	{
		if (philo->info->time_to_eat > philo->info->time_to_sleep)
			ft_usleep(philo->info->time_to_eat - philo->info->time_to_sleep);
	}
}

static void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_fun(philo, "has taken a fork");
	ft_usleep(philo->info->time_to_die);
	pthread_mutex_unlock(philo->l_fork);
}

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (died_alert(philo, 0) == 1)
			break ;
		if (philo->info->num_philo == 1)
		{
			one_philo(philo);
			break ;
		}
		grab_forks(philo);
		philo_eat(philo);
		if (died_alert(philo, 0) == 1)
			break ;
		print_fun(philo, "is sleeping");
		ft_usleep(philo->info->time_to_sleep);
		if (died_alert(philo, 0) == 1)
			break ;
		philo_think(philo);
	}
	return (NULL);
}
