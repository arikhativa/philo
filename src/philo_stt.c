/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:37:26 by yoav              #+#    #+#             */
/*   Updated: 2022/11/03 17:13:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *p)
{
	p->stt = EAT;
	p->eat_time = timer_get_now();
	print_action(p, "is eating");
	sleep_wrapper(p->i->time_to_eat);
}

void	philo_sleep(t_philo *p)
{
	p->stt = SLEEP;
	print_action(p, "is sleeping");
	sleep_wrapper(p->i->time_to_sleep);
}

void	philo_thinking(t_philo *p)
{
	p->stt = THINK;
	print_action(p, "is thinking");
}

int	philo_is_dead(t_philo *p)
{
	long	now;
	
	now = timer_get_now();
	if ((now - p->eat_time) > p->starvation_limit)
	{
		p->stt = DIED;
		print_action(p, "died");
		return (TRUE);
	}
	return (FALSE);
}
