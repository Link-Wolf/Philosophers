/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:41 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/23 15:07:18 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# ifndef T_FORK
#  define T_FORK

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				is_held;
}	t_fork;
# endif

# ifndef T_PHILO
#  define T_PHILO

typedef struct s_philo
{
	long long		start;
	int				nb;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				to_eat;
	int				sim;
	long long		*since_eat;
	long long		*since_change;
	int				*turn;
	int				*status;
	int				*eat_times;
	int				turn_count;
	pthread_mutex_t	waiter;
	t_fork			**forks;
}	t_philo;
# endif

# ifndef T_INDEXED
#  define T_INDEXED

typedef struct s_indexed
{
	int		index;
	t_philo	*philo;
}	t_indexed;
# endif

enum
{
	THINK = 0,
	EAT	= 1,
	DEATH = 2,
	FORK = 3,
	SLEEP = 4
};

int			ft_atoi(const char *str);
void		*job(void *idx);
long long	now(void);
void		message(int index, t_philo *philo, int status);
void		ft_bzero(void *s, size_t n);
void		turn_update(t_philo *philo);
void		*ft_calloc(size_t count, size_t size);
void		check_cornucopia(t_philo *philo);
void		dinner_is_served(t_philo *philo);

#endif
