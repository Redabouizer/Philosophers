/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:01:03 by rbouizer          #+#    #+#             */
/*   Updated: 2024/08/26 18:05:08 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data *init_data(char **info, int count)
{
    t_data *data;
    data = malloc(sizeof(t_data));
    if (data == NULL)
       return (0);
    
    if (ft_atoi(info[1]) > 200)
        return (0);
    data->nb_philo = ft_atoi(info[1]);
    data->time_to_die = ft_atoi(info[2]);
    data->time_to_eat = ft_atoi(info[3]);
    data->time_to_sleep = ft_atoi(info[4]);
    data->is_died = 0 ;
    if(count == 6)
        data->time_to_m_eat = ft_atoi(info[5]);
    data->time_to_start= timestamp();
    //printf("nb_philo : %llu , time_to_die : %llu , time_to_eat : %llu , time_to_sleep : %llu , time_to_m_eat : %llu ,  time_to_start : %llu",data->nb_philo, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->time_to_m_eat,  data->time_to_start );
    return data ;
}

t_philo *init_philo(int id, t_data *data)
{
    t_philo *philo;

    philo = malloc(sizeof( t_philo));
    if (philo == NULL)
       return (0);
    philo->id = id;
    philo->data = data;
    philo->fork_l =NULL;
    philo->fork_r = NULL;
    philo->num_eat = 0;
    return philo;
}

t_philos *init_philos(char **nb)
{
    t_philos *philos;

    philos = malloc(sizeof( t_philos));
    if (philos == NULL)
       return (0);
    philos->nb_philo = ft_atoi(nb[1]);
    if (!philos->nb_philo ||  ft_atoi(nb[1])== 1)
		return (0);
    philos->thread = NULL;
    philos->fork =NULL;
    philos->top= NULL;
    philos->bottom= NULL;
    return philos;
}



