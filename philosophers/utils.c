/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 03:00:00 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/02/26 17:57:45 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long ms)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(100);
}

int	died_alert(t_philo *philo, int check)
{
	int	status;

	pthread_mutex_lock(&philo->info->dead_mutex);
	if (check == 1)
		philo->info->is_dead = 1;
	status = philo->info->is_dead;
	pthread_mutex_unlock(&philo->info->dead_mutex);
	return (status);
}

void	print_fun(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->dead_mutex);
	if (philo->info->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->info->dead_mutex);
		pthread_mutex_unlock(&philo->info->print_mutex);
		return ;
	}
	printf("%lld %d %s\n", get_time() - philo->info->start_time,
		philo->id, str);
	pthread_mutex_unlock(&philo->info->dead_mutex);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

int	free_fork(t_philo_info *info, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->dead_mutex);
	pthread_mutex_destroy(&info->meal_mutex);
	if (info->fork_mutex)
		free(info->fork_mutex);
	return (0);
}
