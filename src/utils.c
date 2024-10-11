/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:00:53 by rbouizer          #+#    #+#             */
/*   Updated: 2024/10/11 17:36:58 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

int	is_number(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] && nb[i] == ' ')
		i++;
	if (nb == NULL || nb[i] == '\0')
		return (0);
	i = 0;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t	r;
	int		i;

	i = 0;
	r = 0;
	while ((*(str + i) >= '0' && *(str + i) <= '9') && *(str + i))
	{
		r = r * 10 + str[i] - '0';
		if (r > 2147483647)
			return (-1);
		i++;
	}
	return ((int)r);
}

int	check_number(char *nb[])
{
	int	i;

	i = 1;
	while (nb[i] != NULL)
	{
		if (!is_number(nb[i]) || ft_atoi(nb[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

uint64_t	timestamp(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

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
