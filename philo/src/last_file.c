/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:06:07 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/23 15:07:23 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_cornucopia(t_philo *philo)
{
	int	bool_but_not;
	int	i;

	bool_but_not = 1;
	i = 0;
	while (i < philo->nb)
		bool_but_not &= (philo->eat_times[i++] >= philo->to_eat);
	if (bool_but_not)
		philo->sim = 0;
}

void	dinner_is_served(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb / 2)
		philo->turn[2 * i++] = 1;
}
