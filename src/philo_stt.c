/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:37:26 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 15:51:56 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *p)
{
	p->stt = EAT;
	print_action(p->start_time, p->id, "is eating");
	p->eat_time = timer_get_now();
	usleep(EAT_TIME);
}

void	philo_sleep(t_philo *p)
{
	p->stt = SLEEP;
	print_action(p->start_time, p->id, "is sleeping");
	usleep(SLEEP_TIME);
}

void	philo_thinking(t_philo *p)
{
	p->stt = THINK;
	print_action(p->start_time, p->id, "is thinking");
}

void	philo_is_dead(t_philo *p)
{
	long	now;
	
	now = timer_get_now();
	if ((now - p->eat_time) > p->eat_limit)
	{
		p->stt = DIED;
		print_action(p->start_time, p->id, "died");
	}
}
