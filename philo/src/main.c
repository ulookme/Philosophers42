/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:29:06 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/14 14:41:08 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Core function of the simulation programm
 *
 * @param	argc: Amount of arguments
 * @param	argv: List of arguments
 * @return	Error code (0 for success)
 */
int main(int argc, char **argv)
{
	t_philosopher 	*build;

	build = parse(argc, argv);
	if (!build)
		return (1);
	runtime(build);
	free(build->forks);
	free(build->philo);
	free(build);
	return (0);
}