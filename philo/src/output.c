/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:49:03 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/18 12:51:45 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Interprets and converts the timeval structure
 * into a long integer in MS
 *
 * @param	timestamp: Structure to convert
 * @return	Converted timestamp
 */
long long	time_convert(struct timeval timestamp)
{
	return ((timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000));
}

/* Calculates the time elapsed since given timestamp
 *
 * @param	timestamp: Timestamp to differ from
 * @return	Returns a new struct, containing differences
 */
struct timeval	elapsed(struct timeval timestamp)
{
	struct timeval		diff;
	struct timeval		current;

	gettimeofday(&current, NULL);
	diff.tv_sec = current.tv_sec - timestamp.tv_sec;
	diff.tv_usec = current.tv_usec - timestamp.tv_usec;
	return (diff);
}

/* Calculates the time elapsed since given timestamp
 * and converts its result into long integer in MS
 *
 * @param	timestamp: Timestamp to differ from
 * @return	Returns the diff converted into MS
 */
long long	elapsed_convert(struct timeval timestamp)
{
	return (time_convert(elapsed(timestamp)));
}

/* Display an log message depending on the log
 * code given
 *
 * @param	logcode: Log code to display philo
 * @param	philo: Philo struct requierd by most log messages
 */
void	log_msg(enum e_logCode logcode, t_philo *philo)
{
	if (logcode < 1)
		return ;
	pthread_mutex_lock(&philo->runtime->write_protec);
	printf("\033[92;1m[%lld ms] Philo n*%d \033[0;1m: \033[0m",
		elapsed_convert(philo->runtime->start), philo->id);
	if (logcode == FORK)
		printf("\033[93mhas taken a fork 🍴");
	else if (logcode == EAT)
		printf("\033[33mis now eating 🍝");
	else if (logcode == SLEEP)
		printf("\033[36mis now sleeping 💤");
	else if (logcode == THINK)
		printf("\033[95mis now thinking 🤔");
	else if (logcode == DIE)
		printf("\033[31;1mhas died! 💀");
	printf("\033[0m\n");
	pthread_mutex_unlock(&philo->runtime->write_protec);
}

/* Display an error message depending on the
 * error code given
 *
 * @param	errcode: Error code to display
 * @param	freeable: In case anything should be freed
 * @return	Returns NULL
 */
void	*error_msg(enum e_errCode errcode, void *freeable)
{
	if (freeable)
		free(freeable);
	if (errcode < 1)
		return (NULL);
	printf("\033[31;1mERROR: \033[0;31m");
	if (errcode == LOW_ARGS)
		printf("Not enough arguments!");
	else if (errcode == MANY_ARGS)
		printf("Too many arguments!");
	else if (errcode == MEMORY_FAIL)
		printf("Memory allocation failed!");
	else if (errcode == INVALID_ARGS)
		printf("Invalid arguments!");
	printf("\033[0m\n");
	return (NULL);
}
