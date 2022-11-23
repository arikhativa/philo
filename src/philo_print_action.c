/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *p, const char *msg, long time)
{
	if (!philo_is_simulation_on(p))
		return ;
	pthread_mutex_lock(p->print_mutex);
	if (philo_is_simulation_on(p))
		printf("%ld %d %s\n", (time - p->start_time), p->id, msg);
	pthread_mutex_unlock(p->print_mutex);
}

void	print_action_no_lock(t_philo *p, const char *msg, long time)
{
	if (!philo_is_simulation_on(p))
		return ;
	printf("%ld %d %s\n", (time - p->start_time), p->id, msg);
}

void	print_action_lock(t_philo *p)
{
	pthread_mutex_lock(p->print_mutex);
}

void	print_action_unlock(t_philo *p)
{
	pthread_mutex_unlock(p->print_mutex);
}

void	print_dead(t_philo *p)
{
	pthread_mutex_lock(p->print_mutex);
	printf("%ld %d %s\n", (p->time_of_death - p->start_time), p->id, \
		"died");
	pthread_mutex_unlock(p->print_mutex);
}
