/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:50:09 by rbouizer          #+#    #+#             */
/*   Updated: 2024/10/21 02:16:42 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_philos *philos)
{
	t_philo	*tmp;

	tmp = philos->top;
	while (1)
	{
		pthread_mutex_lock(&tmp->data->mutex);
		if ((int)((timestamp() - tmp->data->time_to_start)
			- tmp->last_eat) >= (int)tmp->data->time_to_die)
		{
			tmp->data->is_died = 1;
			pthread_mutex_lock(&tmp->data->lock);
			printf("%llu %d die\n",
				(timestamp() - tmp->data->time_to_start), tmp->id);
			return (free(philos->thread), free(philos));
		}
		if (tmp->data->cmp == philos->nb_philo)
		{
			pthread_mutex_lock(&tmp->data->lock);
			return (free(philos->thread), free(philos));
		}
		pthread_mutex_unlock(&tmp->data->mutex);
		tmp = tmp->next;
	}
}

int	init_forks(t_philos *philos)
{
	t_philo	*node;
	int		i;

	i = -1;
	philos->fork = malloc(sizeof(pthread_mutex_t) * philos->nb_philo);
	if (!philos->fork)
		return (0);
	node = philos->top;
	while (++i < philos->nb_philo)
	{
		if (pthread_mutex_init(&philos->fork[i], NULL))
			return (0);
	}
	i = 0;
	node->fork_r = &philos->fork[i];
	node->fork_l = &philos->fork[philos->nb_philo - 1];
	(1) && (node = node->next, i++);
	while (i < philos->nb_philo)
	{
		node->fork_r = &philos->fork[i];
		node->fork_l = &philos->fork[i - 1];
		node = node->next;
		i++;
	}
	return (1);
}

int	init_thread(t_philos *philos, t_data *data)
{
	t_philo	*tmp;
	int		i;

	i = -1;
	philos->thread = malloc(sizeof(pthread_t) * philos->nb_philo);
	if (!philos->thread)
		return (0);
	tmp = philos->top;
	data->time_to_start = timestamp();
	while (++i < philos->nb_philo)
	{
		if (pthread_create(&philos->thread[i], NULL, &routine, tmp))
			return (0);
		if (pthread_detach(philos->thread[i]))
			return (0);
		tmp = tmp->next;
	}
	monitor(philos);
	return (1);
}

int	ft_init_pro(t_philos **philos, t_data **data)
{
	if (!init_forks(*philos))
		return (0);
	if (!init_thread(*philos,*data))
		return (0);
	return (1);
}
