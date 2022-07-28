/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:17:34 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/27 12:25:06 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Converts a string to its corresponding integer function atoi()
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

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		pthread_mutex_init(&(rules->forks[i]), NULL);
	}
	pthread_mutex_init(&(rules->writing), NULL);
	pthread_mutex_init(&(rules->check_eat), NULL);
	return (SUCESS);
}

int	init_philosophe(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		rules->philosophes[i].id = i;
		rules->philosophes[i].left_fork = i;
		rules->philosophes[i].right_fork = (i + 1) % rules->nb_philo;
		rules->philosophes[i].last_eat = 0;
		rules->philosophes[i].ate = 0;
		rules->philosophes[i].rules = rules;
	}
	return (SUCESS);
}

int	init_all(t_rules *rules, char **argv)
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->nb_eat = ft_atoi(argv[5]);
	rules->died = 0;
	rules->all_ate = 0;
	if (rules->nb_philo < 1 || rules->time_to_die < 60
		|| rules->time_to_eat < 60 || rules->time_to_sleep < 60
		|| rules->nb_philo > 200)
		return (FAILURE);
	if (argv[5])
		if (rules->nb_eat < 1)
			return (FAILURE);
	init_mutex(rules);
	init_philosophe(rules);
	return (SUCESS);
}
