/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:48:14 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/29 13:00:15 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <printf.h>
# include <pthread.h>
# include <unistd.h>

# include "hand.h"
# include "fork.h"
# include "macros.h"
# include "error_code.h"

typedef enum e_philo_stt
{
	THINK,
	EAT,
	SLEEP,
}	t_philo_stt;

typedef struct s_philo
{
	int			id;
	pthread_t	tid;
	t_philo_stt	stt;
	t_hand		*left_hand;
	t_hand		*right_hand;
}	t_philo;


void			philo_destroy(t_philo *p);
t_error_code	philo_create(t_philo **ret, int id, t_fork *l, t_fork *r);
void 			*philo_handler(void *arg);
t_error_code	philo_start_simulation(t_philo *p);
t_error_code	philo_stop_simulation(t_philo *p);

#endif
