/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:29:06 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/14 13:54:58 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Starting point of philo's threads
 *
 * @param	philo: Individual's philo struct
 * @return	NULL pointer
 */
static void		*philo_thread(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *) arg;
	return (NULL);
}

/* Initialize a philosopher's thread and
 * sets its variables
 *
 * @param	data: Core structure of the simulation
 * @return	Returns the corresponding philo structure
 */
t_philo	*init_philo(t_philosopher *data, int i)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	philo->nb_eating = 0;
	philo->runtime = data;
	philo->left = &data->forks[i % data->nb_philo];
	philo->right = &data->forks[(i + 1) % data->nb_philo];
	gettimeofday(&philo->last_time_eat, NULL);
	pthread_create(&philo->thread, NULL, philo_thread, philo);
	return (philo);
}