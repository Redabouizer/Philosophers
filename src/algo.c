/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:00:58 by rbouizer          #+#    #+#             */
/*   Updated: 2024/12/08 16:30:04 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->is_died)
		return (0);
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_lock(philo->fork_r);
	return (1);
}

static void	less_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d is sleeping\n",
		(timestamp() - philo->data->time_to_start), philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	get_sleep(philo->data->time_to_sleep);
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d is thinking\n",
		timestamp() - philo->data->time_to_start, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
}

static void	eating(t_philo *philo)
{
	if (!check_eat(philo))
		return ;
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d has taken a fork\n",
		(timestamp() - philo->data->time_to_start), philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(philo->fork_l);
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d has taken a fork\n",
		(timestamp() - philo->data->time_to_start), philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d is eating\n",
		(timestamp() - philo->data->time_to_start), philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	get_sleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->mutex);
	philo->num_eat++;
	if (philo->num_eat == philo->data->time_to_m_eat)
		philo->data->cmp++;
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->mutex);
	philo->last_time_to_eat = timestamp();
	pthread_mutex_unlock(&philo->data->mutex);
	less_fork(philo);
}

void	*routine(void *philo)
{
	if (((t_philo *)philo)->num_eat == ((t_philo *)philo)->data->time_to_m_eat)
		return (0);
	if (((t_philo *)philo)->id % 2 == 0)
		usleep(100);
	while (1)
	{
		eating(philo);
		usleep(300);
	}
	return (0);
}

int	term(char **info, int count)
{
	t_data		*data;
	t_philos	*philos;

	(1) && (data = NULL, philos = NULL);
	if (!ft_init(info, count, &data, &philos))
		return (0);
	if (!ft_init_pro(&philos, &data))
		return (0);
	return (1);
}
