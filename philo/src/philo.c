/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:29:06 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/12 14:29:08 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"
/* Specialized function for die check
 *
 * @param	runtime: Core structure for simulation
 */
void	dead_task(t_philosopher *runtime)
{
    size_t i;

    i = 0;
    while (i < runtime->nb_philo && runtime->actif_or_not)
    {
        if (runtime->time_to_die < elapsed_convert(runtime->philo[i].last_time_eat))
        {
            log_msg(DIE, &runtime->philo[i]);
            runtime->actif_or_not = 0;
        }
        i++;
        if (i >= runtime->nb_philo && runtime->actif_or_not)
            i = 0;
    }
}
