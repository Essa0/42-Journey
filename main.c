/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:44:04 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/02/25 03:10:51 by  iabiesat        ###   ########.fr       */
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
		free (info->fork_mutex);
	return (0);
}

int	init_table(t_philo_info *info)
{
	int	i;

	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->fork_mutex)
		return (1);
	i = 0;
	info->is_dead = 0;
	if (pthread_mutex_init(&info->print_mutex, NULL) != 0)
	{
		free(info->fork_mutex);
		return (1);
	}
	if (pthread_mutex_init(&info->dead_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&info->print_mutex);
		free(info->fork_mutex);
		return (1);
	}
	if (pthread_mutex_init(&info->meal_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&info->print_mutex);
		pthread_mutex_destroy(&info->dead_mutex);
		free(info->fork_mutex);
		return (1);
	}
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

void	*routine_philo(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (died_alert(philo, 0) == 1)
			break;
		if (philo->info->num_philo == 1)
		{
			pthread_mutex_lock(philo->l_fork);
			print_fun(philo, "has taken a fork");
			ft_usleep(philo->info->time_to_die);
			pthread_mutex_unlock(philo->l_fork);
			break;
		}
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
		print_fun(philo, "is eating");
		pthread_mutex_lock(&philo->info->meal_mutex);
		philo->last_time_eat = get_time();
		philo->num_meals_eaten++;
		pthread_mutex_unlock(&philo->info->meal_mutex);
		ft_usleep(philo->info->time_to_eat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (died_alert(philo, 0) == 1)
			break;
		print_fun(philo, "is sleeping");
		ft_usleep(philo->info->time_to_sleep);
		if (died_alert(philo, 0) == 1)
			break;
		print_fun(philo, "is thinking");
		if (philo->info->num_philo % 2 == 1)
		{
			if (philo->info->time_to_eat > philo->info->time_to_sleep)
				ft_usleep(philo->info->time_to_eat - philo->info->time_to_sleep);
		}
	}
	return NULL;
}

int	waiter(t_philo *philo)
{
	int 		i;
	int 		x;
	int			meal_eaten;
	long long	last_meal;

	while (1)
	{
		i = 0;
		x = 0;
		while (i < philo[0].info->num_philo)
		{
			pthread_mutex_lock(&philo[0].info->meal_mutex);
			last_meal = philo[i].last_time_eat;
			meal_eaten = philo[i].num_meals_eaten;
			pthread_mutex_unlock(&philo[0].info->meal_mutex);
			if ((get_time() - last_meal) >= philo[0].info->time_to_die)
			{
				pthread_mutex_lock(&philo[0].info->print_mutex);
				pthread_mutex_lock(&philo[0].info->dead_mutex);
				philo[0].info->is_dead = 1;
				printf("%lld %d died\n", get_time() - philo[0].info->start_time, philo[i].id);
				pthread_mutex_unlock(&philo[0].info->dead_mutex);
				pthread_mutex_unlock(&philo[0].info->print_mutex);
				return (1);
			}
			if (philo[0].info->must_eat != -1 && meal_eaten 
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
	int	i;
	int	j;

	info->start_time = get_time();
	i = 0;
	while (i < info->num_philo)
	{
		philo[i].last_time_eat = info->start_time;
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_create(&philo[i].th, NULL, &routine_philo, &philo[i]) != 0)
		{
			died_alert(&philo[0], 1);
			j = 0;
			while (j < i)
			{
				pthread_join(philo[j].th, NULL);
				j++;
			}
			return (1);
		}
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
		printf("%s", ERR_MSG);
		return (1);
	}
	if (init_table(&info) != 0)
		return (1);
	if (init_philo(&philo, &info) != 0)
	{
		free_fork(&info, info.num_philo);
		return (1);
	}
	if (create_philo(&info, philo) != 0)
	{
		free_fork(&info, info.num_philo);
		free(philo);
		return (1);
	}
	waiter(philo);
	i = 0;
	while (i < info.num_philo)
	{
		pthread_join(philo[i].th, NULL);
		i++;
	}
	free_fork(&info, info.num_philo);
	free(philo);
	return (0);
}

