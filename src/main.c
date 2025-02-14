/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:17:39 by rbouizer          #+#    #+#             */
/*   Updated: 2024/12/08 16:19:29 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	timestamp(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	main(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error: Check number of arguments", 2), 1);
	if (!check_number(av))
		return (ft_putstr_fd("Error: Invalid arguments", 2), 1);
	if (!term(av, ac))
		return (ft_putstr_fd("Error: Failed to initialize simulation", 2), 1);
	return (0);
}
