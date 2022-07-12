/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:05:52 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/12 17:33:17 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
int main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf('invalide number'));
	t_philosopher build;
	build.nb_philo = ft_atoi(argv[1]);
	build.time_to_die = ft_atoi(argv[2]);
	build.time_to_eat = ft_atoi(argv[3]);
	build.time_to_sleep = ft_atoi(argv[4]);
	build.nb_must_eat = ft_atoi(argv[5]);


}
