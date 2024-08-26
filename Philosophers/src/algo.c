/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:00:58 by rbouizer          #+#    #+#             */
/*   Updated: 2024/08/26 00:27:05 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int term(char **info, int count)
{
  t_data *data;
  t_philo *philo;
  t_philos *philos;
  int i;

  i = 1;
  data = init_data(info, count);
  if (!data)
    return (0);
  philos = init_philos(info);
  if (!philos)
    return (free(data), 0);
  while (i < count)
  {
    philo = init_philo(i, data);
    if (!philo)
      return (free(philos), free(data), 0);
    add_back(philos, philo);
    i++;
  }
  philos->bottom->next = philos->top;
  return 0;
}