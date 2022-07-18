/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:49:29 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/18 12:49:34 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* Specialized function for die check philo
 *
 * @param	runtime: Core structure for simulation
 */
void	dead_task(t_philosopher *runtime)
{
	size_t	i;

	i = 0;
	while (i < runtime->nb_philo && runtime->actif_or_not)
	{
		if (runtime->time_to_die < \
		elapsed_convert(runtime->philo[i].last_time_eat))
		{
			log_msg(DIE, &runtime->philo[i]);
			runtime->actif_or_not = 0;
		}
		i++;
		if (i >= runtime->nb_philo && runtime->actif_or_not)
			i = 0;
	}
}
