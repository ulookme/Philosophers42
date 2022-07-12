/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:54:03 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/12 15:55:41 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>
# include<semaphore.h>
# include<unistd.h>

struct s_philo;

typedef struct s_struc_philosopher
{
	int				actif_or_not;
	unsigned int	nb_philo;
	unsigned int	time_to_die;
	unsigned int 	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	nb_must_eat;
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t write_protec;

}	t_philosopher;

typedef struct s_philo
{
	pthread_mutex_t	*right;
	pthread_mutex_t *left;
	unsigned int	nb_eating;
	struct timeval	last_time_eat;
	t_philosopher	*runtime;

}	t_philo;


#endif
