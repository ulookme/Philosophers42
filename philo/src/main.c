/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:39:33 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/27 13:06:31 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ac < 5)
		return ((int)error_msg(LOW_ARGS, NULL));
	else if (ac > 6)
		return ((int)error_msg(MANY_ARGS, NULL));
	if (init_all(&rules, av) == FAILURE)
		return (printf("\033[91mERROR : initialisation echoue !\n"));
	if (start_thread(&rules) == FAILURE)
		return (printf("\033[91mERROR : erreur dans la creation des threads!\n"));
	return (SUCESS);
}
