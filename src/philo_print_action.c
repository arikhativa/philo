/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:42:52 by yoav              #+#    #+#             */
/*   Updated: 2022/11/08 15:13:47 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *p, const char *msg, long time)
{
	if (!philo_is_simulation_on(p))
		return ;
	pthread_mutex_lock(&(p->print_mutex));
	printf("%ld %d %s\n", (time - p->start_time), p->id, msg);
	pthread_mutex_unlock(&(p->print_mutex));
}

void	print_action_no_lock(t_philo *p, const char *msg, long time)
{
	if (!philo_is_simulation_on(p))
		return ;
	printf("%ld %d %s\n", (time - p->start_time), p->id, msg);
}

void	print_action_lock(t_philo *p)
{
	pthread_mutex_lock(&(p->print_mutex));
}

void	print_action_unlock(t_philo *p)
{
	pthread_mutex_unlock(&(p->print_mutex));
}

void	print_dead(t_philo *p)
{
	pthread_mutex_lock(&(p->print_mutex));
	printf("%ld %d %s\n", (p->time_of_death - p->start_time), p->id, \
		"died");
	pthread_mutex_unlock(&(p->print_mutex));
}
