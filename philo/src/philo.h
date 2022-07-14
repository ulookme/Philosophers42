/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:54:03 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/14 13:52:53 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

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
	pthread_t		thread;

}	t_philo;

int				ft_atoi(const char *str);
void			*error_msg(int errcode, void *freeable);
t_philosopher	*init_args(char **args);
t_philosopher	*parse(int argc, char **argv);
t_philo			*init_philo(t_philosopher *data, int i);

#endif /* PHILO_H */