/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:03:34 by rbouizer          #+#    #+#             */
/*   Updated: 2024/08/26 18:16:30 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	long long nb_philo;
	uint64_t time_to_die;
	uint64_t time_to_eat;
	uint64_t time_to_sleep;
	long long time_to_m_eat;
	uint64_t time_to_start;
	int is_died;

}   t_data;

typedef struct s_philo
{
	unsigned int		id;
	struct s_data *data;
	pthread_mutex_t *fork_l;
	pthread_mutex_t *fork_r;
	uint64_t num_eat;
	struct s_philo *next;
}   t_philo;

typedef struct s_philos
{
	long long nb_philo;
	pthread_t *thread;
	pthread_mutex_t *fork;
	t_philo *top;
	t_philo *bottom;
}   t_philos;

int ft_atoi(const char *str);
int check_number(char *nb[]);
int term(char **info, int count );
uint64_t	timestamp();
void	add_back(t_philos *philos, t_philo *philo);
t_data *init_data(char **info, int count);
t_philo *init_philo(int id, t_data *data);
t_philos *init_philos(char **nb);
void	ft_putstr_fd(char *s, int fd);
#endif