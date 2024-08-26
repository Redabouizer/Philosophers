/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:17:39 by rbouizer          #+#    #+#             */
/*   Updated: 2024/08/26 18:06:59 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char *av[])
{
    if(ac != 5  && ac != 6 )
        return ft_putstr_fd("Error: Check number of arguments", 2), 1;
    if (!check_number(av))
        return ft_putstr_fd("Error: Invalid arguments", 2), 1;
    if (!term(av, ac))
        return ft_putstr_fd("Error:", 2), 1;
    return 0;
}




// void routine()
// {
//     eat();
//     slep();
//     think();
// }

// void init_fok()
// {
//     t_philos piloo;
//     piloo.tab = malloc(pthread_mutex_t * piloo->nb_philo);
//     int i = 0;
//     while (i < num_p)
//     {
//         top->fork_l = nta3i;
//         top->fork_r = dyalsahbi;
//         top = top->next;
//         i++;
//     }
    
// }

