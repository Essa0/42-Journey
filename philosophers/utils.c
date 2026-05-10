/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 03:00:00 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/05/10 13:07:00 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
	get_time on standard gettimeofday the function give us the time in
	sec and ms so every time 

	ft_usleep i face separate issues with standared usleep for example when
	the philo sleep for 5ms it cause late with wake him up so mybe will the
	philo wake up after 7ms because of the os be busy in another thing so 
	we customize one to be sure that philo sleep and wakeup on time :)
*/
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(t_philo *philo, long long ms)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		if (died_alert(philo, 0) == 1)
			break ;
		usleep(100);
	}
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
	cleanup_all(info);
	if (info->fork_mutex)
		free(info->fork_mutex);
	return (0);
}
