/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:48:14 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/29 15:51:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <printf.h>
# include <pthread.h>
# include <unistd.h>

# include "print_action.h"
# include "hand.h"
# include "fork.h"
# include "macros.h"
# include "error_code.h"

typedef enum e_philo_stt
{
	THINK,
	EAT,
	SLEEP,
	DIED,
}	t_philo_stt;

typedef struct s_philo
{
	int			id;
	long		start_time;
	long		eat_time;
	long		eat_limit;
	pthread_t	tid;
	t_philo_stt	stt;
	t_hand		*left_hand;
	t_hand		*right_hand;
}	t_philo;

// philo
void			philo_destroy(t_philo *p);
t_error_code	philo_create(t_philo **ret, int id, t_fork *l, t_fork *r, long start_time);

// fork
t_error_code	philo_pick_fork_left(t_philo *p);
t_error_code	philo_pick_fork_right(t_philo *p);
void			philo_drop_fork_right(t_philo *p);
void			philo_drop_fork_left(t_philo *p);
void			philo_drop_forks(t_philo *p);

// handler
void 			*philo_handler(void *arg);

// thread
t_error_code	philo_start_simulation(t_philo *p);
t_error_code	philo_stop_simulation(t_philo *p);

// stt
void	philo_eat(t_philo *p);
void	philo_sleep(t_philo *p);
void	philo_thinking(t_philo *p);
void	philo_is_dead(t_philo *p);

#endif
