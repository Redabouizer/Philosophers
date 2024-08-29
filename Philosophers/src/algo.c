/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:00:58 by rbouizer          #+#    #+#             */
/*   Updated: 2024/08/28 18:31:26 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int eat()
// {
    
// }

// int sleep()
// {
    
// }

// int think()
// {
    
// }

void *routine(void *arg) {
    t_philos *philos = (t_philos *)arg;
    printf("%lld\n", philos->nb_philo);

    // if (!eat()) {
    //     return NULL;
    // }
    // if (!sleep()) {
    //     return NULL;
    // }
    // if (!think()) {
    //     return NULL;
    // }

    return NULL;
}

int term(char **info, int count) {
    t_data *data;
    t_philo *philo;
    t_philos *philos;

    data = NULL; philo = NULL ; philos = NULL;
    if(!ft_init(info, count, &data, &philo, &philos))
        return 0;
    if(!ft_init_pro(&philos, &data))
        return 0;
    return 1;
}