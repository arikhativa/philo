/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:48:14 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/07 11:47:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <printf.h>
# include <pthread.h>
# include <unistd.h>

# include "sleep_wrapper.h"
# include "hand.h"
# include "timer.h"
# include "input.h"
# include "fork.h"
# include "macros.h"
# include "error_code.h"

typedef enum e_philo_stt
{
	THINK,
	EAT,
	SLEEP,
	DIED,
	DONE_EATING,
}	t_philo_stt;

typedef struct s_philo
{
	int				id;
	int				simulation_is_on;
	long			start_time;
	long			eat_time;
	long			starvation_limit;
	int				num_of_meals;
	long			time_of_death;
	pthread_t		tid;
	t_philo_stt		stt;
	t_hand			*left_hand;
	t_hand			*right_hand;
	t_input			*i;
	pthread_mutex_t	print_mutex;
}	t_philo;

// philo
void			philo_destroy(t_philo *p);
t_error_code	philo_create(t_philo **ret, t_fork *l, t_fork *r);
void			philo_init(t_philo *p, int id, long start_time, t_input *i);

// print
void			print_action(t_philo *p, const char *msg);
void			print_dead(t_philo *p);

// fork
t_error_code	philo_pick_fork_left(t_philo *p);
t_error_code	philo_pick_fork_right(t_philo *p);
void			philo_drop_fork_right(t_philo *p);
void			philo_drop_fork_left(t_philo *p);
void			philo_drop_forks(t_philo *p);

// handler
void			*philo_handler(void *arg);

// thread
t_error_code	philo_start_simulation(t_philo *p);
t_error_code	philo_stop_simulation(t_philo *p);
void			philo_stop(t_philo *p);

// stt
void			philo_eat(t_philo *p);
void			philo_sleep(t_philo *p);
void			philo_thinking(t_philo *p);
int				philo_is_dead(t_philo *p);
int				philo_is_done_eating(t_philo *p);

#endif
