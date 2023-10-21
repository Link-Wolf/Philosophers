/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:37 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/06 12:48:33 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init(t_philo *philo, int n, char *args[]);
static void	set_thread(t_philo *philo);
static void	tini(t_philo *philo);
static int	malloc_pwease(t_philo *philo);

int	main(int argc, char *argv[])
{
	t_philo		*philo;

	if (argc != 5 && argc != 6)
		return (printf("Usage :\n\t./philo [number_of_philosophers] [time_to_di\
e] [time_to_eat] [time_to_sleep] (nb_of_times_each_philosopher_must_eat)"));
	philo = malloc(sizeof(t_philo));
	if (init(philo, argc, argv) >= 0)
		set_thread(philo);
	tini(philo);
	free(philo);
}

static int	init(t_philo *philo, int n, char *args[])
{
	philo->start = now();
	philo->nb = ft_atoi(args[1]);
	philo->die_time = ft_atoi(args[2]);
	philo->eat_time = ft_atoi(args[3]);
	philo->sleep_time = ft_atoi(args[4]);
	if (n == 6)
		philo->to_eat = ft_atoi(args[5]);
	else
		philo->to_eat = 2147483647;
	philo->sim = 1;
	pthread_mutex_init(&philo->waiter, NULL);
	if (malloc_pwease(philo) < 0)
		return (-42);
	dinner_is_served(philo);
	return (0);
}

static int	malloc_pwease(t_philo *philo)
{
	int	i;

	philo->forks = ft_calloc(sizeof(t_fork *), philo->nb);
	philo->since_eat = malloc(sizeof(long long) * philo->nb);
	philo->since_change = malloc(sizeof(long long) * philo->nb);
	philo->turn = ft_calloc(sizeof(int), philo->nb);
	philo->status = malloc(sizeof(int) * philo->nb);
	philo->eat_times = ft_calloc(sizeof(int), philo->nb);
	i = 0;
	if (!philo->forks || !philo->since_eat || !philo->since_change
		|| !philo->turn || !philo->status || !philo->eat_times)
		return (-42);
	while (i < philo->nb)
	{
		philo->forks[i] = malloc(sizeof(t_fork));
		if (!philo->forks)
			return (-42);
		philo->forks[i]->is_held = 0;
		philo->since_eat[i] = now();
		philo->since_change[i] = now();
		pthread_mutex_init(&philo->forks[i++]->mutex, NULL);
	}
	return (0);
}

static void	set_thread(t_philo *philo)
{
	t_indexed	**idx;
	pthread_t	*philosophers;
	int			i;

	idx = malloc(sizeof(t_indexed *) * philo->nb);
	philosophers = malloc(sizeof(pthread_t *) * philo->nb);
	i = 0;
	while (i < philo->nb)
	{
		idx[i] = malloc(sizeof(t_indexed));
		idx[i]->index = i;
		idx[i]->philo = philo;
		pthread_create(&philosophers[i], NULL, job, idx[i]);
		i++;
	}
	while (philo->sim)
		;
	i = 0;
	while (i < philo->nb)
	{
		free(idx[i++]);
		pthread_detach(philosophers[i]);
	}
	free(idx);
	free(philosophers);
}

static void	tini(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb)
	{
		pthread_mutex_destroy(&philo->forks[i]->mutex);
		free(philo->forks[i]);
		i++;
	}
	free(philo->forks);
	free(philo->since_eat);
	free(philo->since_change);
	free(philo->turn);
	free(philo->status);
}
