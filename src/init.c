/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:01:03 by rbouizer          #+#    #+#             */
/*   Updated: 2024/12/08 16:29:48 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_back(t_philos *philos, t_philo *philo)
{
	t_philo	*tmp;

	if (!philos)
		return ;
	if (!philos->top)
	{
		philos->top = philo;
		philos->bottom = philo;
		return ;
	}
	tmp = philos->top;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = philo;
	philos->bottom = philo;
	philos->bottom->next = NULL;
}

t_data	*init_data(char **info, int count)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	if (ft_atoi(info[1]) > 200)
		return (0);
	data->nb_philo = ft_atoi(info[1]);
	data->time_to_die = ft_atoi(info[2]);
	data->time_to_eat = ft_atoi(info[3]);
	data->time_to_sleep = ft_atoi(info[4]);
	data->is_died = 0;
	data->cmp = 0;
	if (count == 6)
		data->time_to_m_eat = ft_atoi(info[5]);
	else
		data->time_to_m_eat = -1;
	data->time_to_start = timestamp();
	pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (data);
}

t_philo	*init_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		return (0);
	philo->id = id;
	philo->data = data;
	philo->fork_l = NULL;
	philo->fork_r = NULL;
	philo->last_time_to_eat = 0;
	philo->num_eat = 0;
	philo->next = NULL;
	return (philo);
}

t_philos	*init_philos(char **nb)
{
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos));
	if (philos == NULL)
		return (0);
	philos->nb_philo = ft_atoi(nb[1]);
	if (!philos->nb_philo || ft_atoi(nb[1]) == 1)
		return (0);
	philos->thread = NULL;
	philos->fork = NULL;
	philos->top = NULL;
	philos->bottom = NULL;
	return (philos);
}

int	ft_init(char **info, int count, t_data **data, t_philos **philos)
{
	int		i;
	t_philo	*philo;

	i = 1;
	*data = init_data(info, count);
	if (!(*data))
		return (0);
	*philos = init_philos(info);
	if (!*philos)
		return (free(*data), 0);
	while (i <= (*philos)->nb_philo)
	{
		philo = init_philo(i, *data);
		if (!philo)
			return (free(*philos), free(*data), 0);
		add_back(*philos, philo);
		i++;
	}
	(*philos)->bottom->next = (*philos)->top;
	return (1);
}
