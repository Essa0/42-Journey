/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:44:04 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/02/22 13:59:48 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_and_parse(int ac, char **av, t_philo_info *info)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	info->num_philo = atoi(av[1]);
	info->time_to_die = atoi(av[2]);
	info->time_to_eat = atoi(av[3]);
	info->time_to_sleep = atoi(av[4]);
	if (ac == 6)
		info->must_eat = atoi(av[5]);
	else
		info->must_eat = -1;
	return (0);
}

int	free_fork(t_philo_info *info)
{
	int	i;
	
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->dead_mutex);
	free (info->fork_mutex);
	return (1);
}

int	init_table(t_philo_info *info)
{
	int	i;

	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->fork_mutex)
		return (1);
	i = 0;
	if (pthread_mutex_init(&info->print_mutex, NULL) != 0)
		return (free_fork(info));
	if (pthread_mutex_init(&info->dead_mutex, NULL) != 0)
		return (free_fork(info));
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork_mutex[i], NULL) != 0)
			return (free_fork(info));
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

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	died_alert(t_philo *philo, int check)
{
	int status;

	pthread_mutex_lock(&philo->info->dead_mutex);
	if (check == 1)
		philo->info->is_dead = 1;
	status = philo->info->is_dead;
	pthread_mutex_unlock(&philo->info->dead_mutex);
	return (status);
}

void	print_fun(t_philo *philo, char *str)
{
	if (died_alert(philo, 0) == 1)
		return ;
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("%lld %d %s\n", get_time() - philo->info->start_time, 
			philo->id, str);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	*routine_philo(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		if (died_alert(philo, 0) == 1)
			break;
		pthread_mutex_lock(philo->l_fork);
		print_fun(philo, "has taken a fork");
		if (philo->info->num_philo == 1)
		{
			usleep(philo->info->time_to_die * 1000);
			pthread_mutex_unlock(philo->l_fork);
			break;
		}
		pthread_mutex_lock(philo->r_fork);
		print_fun(philo, "has taken a fork");
		print_fun(philo, "is eating");
		philo->last_time_eat = get_time();
		usleep(philo->info->time_to_eat * 1000);
		philo->num_meals_eaten++;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		print_fun(philo, "is sleeping");
		usleep(philo->info->time_to_sleep * 1000);
		print_fun(philo, "is thinking");
	}
	return NULL;
}

int	waiter(t_philo *philo)
{
	int i;
	int x;
	while (1)
	{
		i = 0;
		x = 0;
		while (i < philo[0].info->num_philo)
		{
			if ((get_time() - philo[i].last_time_eat) >= 
				philo[0].info->time_to_die)
				{
					print_fun(philo, "died");
					return (died_alert(&philo[0], 1));
				}
			if (philo[0].info->must_eat != -1 && philo[i].num_meals_eaten 
				>= philo[0].info->must_eat)
					x++;
			i++;
		}
		if (philo[0].info->must_eat != -1 && x == philo[0].info->num_philo)
			return(died_alert(&philo[0], 1));
		usleep(1000);
	}
	return (0);
}

int	create_philo(t_philo_info *info, t_philo *philo)
{
	int i;

	info->start_time = get_time();
	i = 0;
	while (i < info->num_philo)
	{
		philo[i].last_time_eat = get_time();
		if (pthread_create(&philo[i].th, NULL, &routine_philo, &philo[i]) != 0)
			return 1;
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo_info	info;
	t_philo			*philo;
	int				i;
	if (ac != 5 && ac != 6)
	{
		printf(ERR_MSG);
		return (1);
	}
	if (validate_and_parse(ac, av, &info) != 0)
	{
		printf(ERR_MSG);
		return (1);
	}
	if (info.num_philo == 0 || info.time_to_die == 0 || 
		info.time_to_sleep == 0 || info.time_to_eat == 0 || info.must_eat == 0)
	{
		printf(ERR_MSG);
		return (1);
	}
	if (init_table(&info) != 0)
		return (1);
	if (init_philo(&philo, &info) != 0)
	{
		free_fork(&info);
		return (1);
	}
	if (create_philo(&info, philo) != 0)
		return (1);
	waiter(philo);
	i = 0;
	while (i < info.num_philo)
	{
		pthread_join(philo[i].th, NULL);
		i++;
	}
	free_fork(&info);
	free(philo);
	return (0);
}
