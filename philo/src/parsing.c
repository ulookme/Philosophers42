/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:05:52 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/14 13:52:55 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Converts a string to its corresponding integer
 * 
 * @param	str: String to convert
 * @return	Converted integer
 */
int	ft_atoi(const char *str)
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

/* Display an error message depending on the
 * error code given
 *
 * @param	errcode: Error code to display
 * @param	freeable: In case anything should be freed
 * @return	Returns NULL
 */
void	*error_msg(int errcode, void *freeable)
{
	if (freeable)
		free(freeable);
	if (errcode < 1)
		return (NULL);
	printf("\033[31;1mERROR: \033[0;31m");
	if (errcode == 1)
		printf("Not enough arguments!");
	else if (errcode == 2)
		printf("Too many arguments!");
	else if (errcode == 3)
		printf("Memory allocation failed!");
	else if (errcode == 4)
		printf("Invalid arguments!");
	printf("\033[0m\n");
	return (NULL);
}

/* Initialize the base structure of the
 * simulation with given args
 *
 * @param	args: Arguments to parse
 * @return	Base structure ready to use
 */
t_philosopher	*init_args(char **args)
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
	return (rules);
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
		return (error_msg(1, NULL));
	else if (argc > 6)
		return (error_msg(2, NULL));
	build = init_args(argv);
	if (!build)
		return (error_msg(3, NULL));
	if (!build->nb_philo || !build->time_to_die
		|| !build->time_to_eat || !build->time_to_sleep)
		return (error_msg(4, build));
	build->philo = malloc(sizeof(t_philo) * build->nb_philo);
	build->forks = malloc(sizeof(pthread_mutex_t) * build->nb_philo);
	if (!build->philo || !build->forks)
		return (error_msg(4, build));
	return (build);
}