/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:48:42 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/18 12:48:47 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Core function of the simulation programm philo
 *
 * @param	argc: Amount of arguments
 * @param	argv: List of arguments
 * @return	Error code (0 for success)
 */
int	main(int argc, char **argv)
{
	t_philosopher	*build;

	build = parse(argc, argv);
	if (!build)
		return (1);
	runtime(build);
	free(build->forks);
	free(build->philo);
	free(build);
	return (0);
}
