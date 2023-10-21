/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:39 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/23 14:42:39 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	message(int index, t_philo *philo, int status)
{
	if (status == THINK)
		printf("%lld %d is thinking\n", now() - philo->start, index);
	else if (status == EAT)
		printf("%lld %d is eating\n", now() - philo->start, index);
	else if (status == DEATH)
		printf("%lld %d died\n", now() - philo->start, index);
	else if (status == FORK)
		printf("%lld %d has taken a fork\n", now() - philo->start, index);
	else if (status == SLEEP)
		printf("%lld %d is sleeping\n", now() - philo->start, index);
}

void	turn_update(t_philo *philo)
{
	int	i;
	int	last;
	int	no_eater_late;

	no_eater_late = 1;
	i = 0;
	while (i < philo->nb)
		no_eater_late &= (philo->status[i++] != EAT);
	if (no_eater_late)
	{
		i = philo->nb - 1;
		last = philo->turn[i];
		while (i >= 1)
		{
			philo->turn[i] = philo->turn[i - 1];
			i--;
		}
		philo->turn[0] = last;
	}
}
// 	else if (philo->nb % 2)
// 	{
// 		i = -1;
// 		while (++i < philo->nb)
// 			philo->turn[i] = (i == 2 * philo->turn_count % philo->nb);
// 	}
// 	else
// 	{
// 		if (no_eating(philo))
// 		{
// 			i = -1;
// 			while (++i < philo->nb)
// 				philo->turn[i] = (i + philo->turn_count) % 2;
// 			philo->turn_count++;
// 		}
// 	}
// 	if (all_ate(philo))
// 		philo->sim = 0;
// }
//
// static int	no_eating(t_philo *philo)
// {
// 	int	i;
//
// 	i = -1;
// 	while (++i < philo->nb)
// 		if (philo->status[i] == EAT)
// 			return (0);
// 	return (1);
// }
//
// // static int	all_ate(t_philo *philo)
// // {
// // 	int	i;
// //
// // 	i = -1;
// // 	while (++i < philo->nb)
// // 		if (philo->eat_times[i] < philo->to_eat)
// // 			return (0);
// // 	return (1);
// // }
