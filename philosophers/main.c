/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:57:04 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/02/26 18:00:14 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_and_parse(int ac, char **av, t_philo_info *info)
{
	if (check_digits(ac, av) != 0)
		return (1);
	info->num_philo = atoi(av[1]);
	info->time_to_die = atoi(av[2]);
	info->time_to_eat = atoi(av[3]);
	info->time_to_sleep = atoi(av[4]);
	if (ac == 6)
		info->must_eat = atoi(av[5]);
	else
		info->must_eat = -1;
	if (info->num_philo <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| info->must_eat == 0)
		return (1);
	return (0);
}
/* 
	in the create_philo we set last_time_eat = start_time to be sure
	that no one appears starved at beginning.
*/

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
				pthread_join(philo[j++].th, NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	join_and_free(t_philo_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_join(philo[i].th, NULL);
		i++;
	}
	free_fork(info, info->num_philo);
	free(philo);
}

int	main(int ac, char **av)
{
	t_philo_info	info;
	t_philo			*philo;

	if (ac != 5 && ac != 6)
		return (write(2, ERR_MSG, 26), 1);
	if (validate_and_parse(ac, av, &info) != 0)
		return (write(2, ERR_MSG, 26), 1);
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
	join_and_free(&info, philo);
	return (0);
}
