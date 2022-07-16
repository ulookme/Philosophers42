/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:54:03 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/14 15:56:29 by flcollar         ###   ########.fr       */
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
	struct timeval	start;
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
	char			id;

}	t_philo;

enum logCode {
	NO_LOG = 0,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

enum errCode {
	NO_ERR = 0,
	LOW_ARGS,
	MANY_ARGS,
	MEMORY_FAIL,
	INVALID_ARGS
};

void			runtime(t_philosopher *data);
void			log_msg(enum logCode logcode, t_philo *philo);
void			*error_msg(enum errCode errcode, void *freeable);
long long		elapsed_convert(struct timeval timestamp);
long long		time_convert(struct timeval timestamp);
struct timeval	elapsed(struct timeval timestamp);
t_philosopher	*parse(int argc, char **argv);
void			dead_task(t_philosopher *runtime);

#endif /* PHILO_H */