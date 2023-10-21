/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:00:18 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/23 15:06:17 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	death(t_philo *philo, int index);
static void	eat(t_philo *philo, int index, int *status);
static void	ft_sleep(t_philo *philo, int index, int *status);
static void	think(t_philo *philo, int index, int *status);

void	*job(void *vars)
{
	t_philo	*philo;
	int		index;

	philo = ((t_indexed *) vars)->philo;
	index = ((t_indexed *) vars)->index;
	philo->status[index] = THINK;
	message(index, philo, THINK);
	while (philo->sim)
	{
		if (now() - philo->since_eat[index] >= philo->die_time)
			death(philo, index);
		else if (philo->status[index] == THINK)
			think(philo, index, &philo->status[index]);
		else if (philo->status[index] == EAT)
			eat(philo, index, &philo->status[index]);
		else if (philo->status[index] == SLEEP)
			ft_sleep(philo, index, &philo->status[index]);
		check_cornucopia(philo);
	}
	return (NULL);
}

static void	death(t_philo *philo, int index)
{
	message(index, philo, DEATH);
	philo->sim = 0;
}

static void	eat(t_philo *philo, int index, int *status)
{
	if (now() - philo->since_change[index] >= philo->eat_time)
	{
		philo->since_change[index] = now();
		philo->forks[index]->is_held = 0;
		pthread_mutex_unlock(&philo->forks[index]->mutex);
		philo->forks[(index + 1) % philo->nb]->is_held = 0;
		pthread_mutex_unlock(&philo->forks[(index + 1) % philo->nb]->mutex);
		message(index, philo, SLEEP);
		*status = SLEEP;
		turn_update(philo);
	}
}

static void	ft_sleep(t_philo *philo, int index, int *status)
{
	if (now() - philo->since_change[index] >= philo->sleep_time)
	{
		philo->since_change[index] = now();
		message(index, philo, THINK);
		*status = THINK;
	}
}

static void	think(t_philo *philo, int index, int *status)
{
	if (philo->nb > 1)
	{
		pthread_mutex_lock(&philo->waiter);
		if (!philo->forks[index]->is_held
			&& !philo->forks[(index + 1) % philo->nb]->is_held
			&& philo->turn[index])
		{
			pthread_mutex_lock(&philo->forks[index]->mutex);
			philo->forks[index]->is_held = 1;
			message(index, philo, FORK);
			pthread_mutex_lock(&philo->forks[(index + 1) % philo->nb]->mutex);
			philo->forks[(index + 1) % philo->nb]->is_held = 1;
			message(index, philo, FORK);
			philo->since_eat[index] = now();
			philo->since_change[index] = now();
			message(index, philo, EAT);
			*status = EAT;
			(philo->eat_times[index])++;
		}
		pthread_mutex_unlock(&philo->waiter);
	}
}
