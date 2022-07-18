/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:49:40 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/18 12:49:43 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

struct	s_philo;

typedef struct s_struc_philosopher
{
	int				actif_or_not;
	unsigned int	nb_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	nb_must_eat;
	struct s_philo	*philo;
	struct timeval	start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_protec;

}	t_philosopher;

typedef struct s_philo
{
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	unsigned int	nb_eating;
	struct timeval	last_time_eat;
	t_philosopher	*runtime;
	pthread_t		thread;
	char			id;

}	t_philo;

enum e_logCode {
	NO_LOG = 0,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

enum e_errCode {
	NO_ERR = 0,
	LOW_ARGS,
	MANY_ARGS,
	MEMORY_FAIL,
	INVALID_ARGS
};

void			runtime(t_philosopher *data);
void			log_msg(enum e_logCode logcode, t_philo *philo);
void			*error_msg(enum e_errCode errcode, void *freeable);
long long		elapsed_convert(struct timeval timestamp);
long long		time_convert(struct timeval timestamp);
struct timeval	elapsed(struct timeval timestamp);
t_philosopher	*parse(int argc, char **argv);
void			dead_task(t_philosopher *runtime);

#endif /* PHILO_H */
