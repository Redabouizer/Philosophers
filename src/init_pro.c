/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:50:09 by rbouizer          #+#    #+#             */
/*   Updated: 2024/08/28 18:24:43 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	node = node->next;
	i++;
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
	return (1);
}

int ft_init_pro(t_philos **philos, t_data **data)
{
    if(!init_forks(*philos))
        return (0);
    if(!init_thread(*philos,*data))
        return (0);
    return 1;
}