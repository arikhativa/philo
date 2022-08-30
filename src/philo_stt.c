/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:37:26 by yoav              #+#    #+#             */
/*   Updated: 2022/08/30 11:12:58 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *p)
{
	p->stt = EAT;
	print_action(p, "is eating");
	p->eat_time = timer_get_now();
	sleep_wrapper(EAT_TIME);
}

void	philo_sleep(t_philo *p)
{
	p->stt = SLEEP;
	print_action(p, "is sleeping");
	sleep_wrapper(SLEEP_TIME);
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
