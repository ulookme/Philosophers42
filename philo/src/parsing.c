/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:05:52 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/14 15:05:55 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Converts a string to its corresponding integer
 * 
 * @param	str: String to convert
 * @return	Converted integer
 */
static int	ft_atoi(const char *str)
{
	long int	res;
	int			negative;

	negative = 1;
	res = 0;
	if (!str)
		return (0);
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

/* Initialize the base structure of the
 * simulation with given args
 *
 * @param	args: Arguments to parse
 * @return	Base structure ready to use
 */
static t_philosopher	*init_args(char **args)
{
	t_philosopher	*rules;

	rules = malloc(sizeof(t_philosopher));
	if (!rules)
		return (NULL);
	rules->nb_philo = ft_atoi(args[1]);
	rules->time_to_die = ft_atoi(args[2]);
	rules->time_to_eat = ft_atoi(args[3]);
	rules->time_to_sleep = ft_atoi(args[4]);
	rules->nb_must_eat = ft_atoi(args[5]);
	rules->actif_or_not = 1;
	return (rules);
}

/* Initializes every mutexes of the core structur
 *
 * @param	build: Core structure of the simulation
 */
static void	init_mutex(t_philosopher *build)
{
	size_t	i;

	build->forks = malloc(sizeof(pthread_mutex_t) * build->nb_philo);
	if (!build->forks)
		return ;
	i = 0;
	while (i < build->nb_philo)
		pthread_mutex_init(&build->forks[i++], NULL);
	pthread_mutex_init(&build->write_protec, NULL);
}

/* Parses the arguments and returns the base
 * structure upon success or NULL upon failure
 * 
 * @param	argc: Arguments count
 * @param	argv: Arguments list
 * @return	Base structure ready to use
 */
t_philosopher	*parse(int argc, char **argv)
{
	t_philosopher	*build;

	if (argc < 5)
		return (error_msg(LOW_ARGS, NULL));
	else if (argc > 6)
		return (error_msg(MANY_ARGS, NULL));
	build = init_args(argv);
	if (!build)
		return (error_msg(MEMORY_FAIL, NULL));
	if (!build->nb_philo || !build->time_to_die
		|| !build->time_to_eat || !build->time_to_sleep)
		return (error_msg(INVALID_ARGS, build));
	build->philo = malloc(sizeof(t_philo) * build->nb_philo);
	if (!build->philo)
		return (error_msg(MEMORY_FAIL, build));
	init_mutex(build);
	if (!build->forks)
	{
		free(build->philo);
		return (error_msg(MEMORY_FAIL, build));
	}
	return (build);
}