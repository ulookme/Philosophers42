/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:29:06 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/14 16:21:51 by chajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Specialized sleep function which ends if sleep time
 * is over OR if simulation ended
 *
 * @param	time: Time to wait in MS
 * @param	data: Core structure of the simulation
 */
static void	wait_task(long long time, t_philosopher *data)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	while (elapsed_convert(current) < time
		&& data->actif_or_not)
		usleep(100);
}

/* Specialized function for eating task
 *
 * @param	philo: Individual's philo structure
 * @param	runtime: Core structure for simulation
 */
static void	eat_task(t_philo *philo, t_philosopher *runtime)
{
	pthread_mutex_lock(philo->left);
	if (!runtime->actif_or_not)
	{
		pthread_mutex_unlock(philo->left);
		return ;
	}
	log_msg(FORK, philo);
	pthread_mutex_lock(philo->right);
	if (!runtime->actif_or_not)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return ;
	}
	log_msg(FORK, philo);
	log_msg(EAT, philo);
	gettimeofday(&philo->last_time_eat, NULL);
	wait_task(runtime->time_to_eat, runtime);
	philo->nb_eating++;
	if (philo->nb_eating > runtime->nb_must_eat)
		runtime->actif_or_not = 0;
	gettimeofday(&philo->last_time_eat, NULL);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

/* Starting point of philo's threads
 *
 * @param	philo: Individual's philo struct
 * @return	NULL pointer
 */
static void		*runtime_thread(void *arg)
{
	t_philo			*philo;
	t_philosopher	*runtime;

	philo = (t_philo *) arg;
	runtime = philo->runtime;
	log_msg(THINK, philo);
	if (runtime->nb_philo == 1)
		wait_task(runtime->time_to_die * 2, runtime);
	else if (philo->id % 2)
		wait_task(runtime->time_to_eat, runtime);
	while (runtime->actif_or_not)
	{
		eat_task(philo, runtime);
		if (!runtime->actif_or_not)
			break ;
		log_msg(SLEEP, philo);
		wait_task(runtime->time_to_sleep, runtime);
		if (!runtime->actif_or_not)
			break ;
		log_msg(THINK, philo);
	}
	return (NULL);
}

/* Initialize a philosopher's thread and
 * sets its variables
 *
 * @param	data: Core structure of the simulation
 * @return	Returns the corresponding philo structure
 */
static t_philo	init_philo(t_philosopher *data, int i)
{
	t_philo		philo;

	philo = data->philo[i];
	philo.nb_eating = 0;
	philo.runtime = data;
	philo.id = i;
	philo.left = &data->forks[i % data->nb_philo];
	philo.right = &data->forks[(i + 1) % data->nb_philo];
	gettimeofday(&philo.last_time_eat, NULL);
	pthread_create(&philo.thread, NULL, runtime_thread, &data->philo[i]);
	return (philo);
}

/* Initialize simulation by starting up every threads and
 * setup its own verifications sessions
 *
 * @param	data: Core structure of the simulation
 */
void	runtime(t_philosopher *data)
{
	size_t	i;

	i = 0;
	gettimeofday(&data->start, NULL);
	while (i < data->nb_philo)
	{
		data->philo[i] = init_philo(data, i);
		i++;
	}
	dead_task(data);
	i = 0;
	while (i < data->nb_philo)
		pthread_join(data->philo[i++].thread, NULL);
}
