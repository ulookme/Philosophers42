/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:16 by chajjar           #+#    #+#             */
/*   Updated: 2022/07/27 12:29:29 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

// MACROS

# define FAILURE -1
# define SUCESS 0

//STRUCTURES

struct	s_rules;

typedef struct s_philosophe
{
	int				id;
	int				right_fork;
	int				left_fork;
	struct s_rules	*rules;
	int				ate;
	long long		last_eat;
	pthread_t		thread;
}	t_philosophe;

typedef struct s_rules
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				died;
	int				all_ate;
	long long		first_timestamp;
	t_philosophe	philosophes[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	writing;
	pthread_mutex_t	check_eat;
}	t_rules;

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

int			init_all(t_rules *rules, char **argv);
int			init_mutex(t_rules *rules);
int			init_philosophe(t_rules *rules);
long long	timestamp(void);
long long	time_diff(long long past, long long current);
void		inter_time(t_rules *rules, int time);
void		print_msg(t_rules *rules, int id, char *msg);
void		*error_msg(enum e_errCode errcode, void *freeable);
void		eating(t_philosophe *p);
void		*p_thread(void *p_data);
void		death(t_rules *rules, t_philosophe *p);
void		end_thread(t_rules *rules, t_philosophe *p);
int			start_thread(t_rules *rules);

#endif /* PHILO_H */
