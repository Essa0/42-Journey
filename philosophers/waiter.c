/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:58:07 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/02/26 17:58:10 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo[0].info->print_mutex);
	pthread_mutex_lock(&philo[0].info->dead_mutex);
	philo[0].info->is_dead = 1;
	printf("%lld %d died\n",
		get_time() - philo[0].info->start_time, philo[i].id);
	pthread_mutex_unlock(&philo[0].info->dead_mutex);
	pthread_mutex_unlock(&philo[0].info->print_mutex);
	return (1);
}

static int	check_death(t_philo *philo, int i)
{
	long long	last_meal;

	pthread_mutex_lock(&philo[0].info->meal_mutex);
	last_meal = philo[i].last_time_eat;
	pthread_mutex_unlock(&philo[0].info->meal_mutex);
	if ((get_time() - last_meal) >= philo[0].info->time_to_die)
		return (print_death(philo, i));
	return (0);
}

static int	check_all_ate(t_philo *philo)
{
	int	i;
	int	x;
	int	meal_eaten;

	if (philo[0].info->must_eat == -1)
		return (0);
	i = 0;
	x = 0;
	while (i < philo[0].info->num_philo)
	{
		pthread_mutex_lock(&philo[0].info->meal_mutex);
		meal_eaten = philo[i].num_meals_eaten;
		pthread_mutex_unlock(&philo[0].info->meal_mutex);
		if (meal_eaten >= philo[0].info->must_eat)
			x++;
		i++;
	}
	if (x == philo[0].info->num_philo)
		return (died_alert(&philo[0], 1));
	return (0);
}

int	waiter(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo[0].info->num_philo)
		{
			if (check_death(philo, i))
				return (1);
			i++;
		}
		if (check_all_ate(philo))
			return (1);
		usleep(1000);
	}
	return (0);
}
