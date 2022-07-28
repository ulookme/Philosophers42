/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:52:26 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/28 11:22:24 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

long long	time_diff(long long past, long long current)
{
	return (current - past);
}

void	inter_time(t_rules *rules, int time)
{
	long long	i;

	i = timestamp();
	while (rules->died == 0)
	{
		if (time_diff(i, timestamp()) > time)
			break ;
		usleep(50);
	}
}

void	print_msg(t_rules *rules, int id, char *msg)
{
	if (rules->died == 0)
	{
		pthread_mutex_lock(&(rules->writing));
		printf("\033[90m%lli ms : ", timestamp() - rules->first_timestamp);
		printf("\033[90mphilosophe %d ", id + 1);
		printf("%s\n", msg);
		pthread_mutex_unlock(&(rules->writing));
	}
	return ;
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
	else if (errcode == INVALID_ARGS)
		printf("Invalid arguments!");
	printf("\033[0m\n");
	return (NULL);
}
