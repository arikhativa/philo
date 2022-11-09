/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:48:14 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/09 11:47:15 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>

# include "sleep_wrapper.h"
# include "hand.h"
# include "timer.h"
# include "input.h"
# include "m_value.h"
# include "fork.h"
# include "macros.h"
# include "error_code.h"

typedef enum e_philo_stt
{
	RUN,
	DIED,
	DONE_EATING,
}	t_philo_stt;

typedef struct s_philo
{
	int				id;
	t_m_value		*simulation_is_on;
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
	pthread_mutex_t	*print_mutex;
}	t_philo;

// philo
void			philo_destroy(t_philo *p);
t_error_code	philo_create(t_philo **ret, t_fork *l, t_fork *r, \
	t_m_value *simulation_is_on);
void			philo_init(t_philo *p, int id, long start_time, t_input *i);
void			philo_init2(t_philo *p, pthread_mutex_t *print_mutex);
void			philo_exit_if_needed(t_philo *p);

// print
void			print_action(t_philo *p, const char *msg, long time);
void			print_dead(t_philo *p);
void			print_action_no_lock(t_philo *p, const char *msg, long time);
void			print_action_lock(t_philo *p);
void			print_action_unlock(t_philo *p);

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
int				philo_is_simulation_on(t_philo *p);

// stt
void			philo_eat_sleep(t_philo *p);
void			philo_thinking(t_philo *p);
int				philo_check_dead(t_philo *p);

#endif
