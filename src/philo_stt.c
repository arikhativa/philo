/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:37:26 by yoav              #+#    #+#             */
/*   Updated: 2022/11/06 13:26:45 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *p)
{
	if (DIED == p->stt || DONE_EATING == p->stt)
		return ;
	p->stt = EAT;
	p->eat_time = timer_get_now();
	print_action(p, "is eating");
	sleep_wrapper(p->i->time_to_eat);
	++p->num_of_meals;
	if (p->num_of_meals == p->i->meals_to_eat)
		p->stt = DONE_EATING;
}

void	philo_sleep(t_philo *p)
{
	if (DIED == p->stt || DONE_EATING == p->stt)
		return ;
	p->stt = SLEEP;
	print_action(p, "is sleeping");
	sleep_wrapper(p->i->time_to_sleep);
}

void	philo_thinking(t_philo *p)
{
	if (DIED == p->stt || DONE_EATING == p->stt)
		return ;
	p->stt = THINK;
	print_action(p, "is thinking");
}

int	philo_is_dead(t_philo *p)
{
	long	now;

	if (DIED == p->stt)
		return (TRUE);
	if (DONE_EATING == p->stt)
		return (FALSE);
	now = timer_get_now();
	if ((now - p->eat_time) > p->starvation_limit)
	{
		p->time_of_death = now;
		p->stt = DIED;
		return (TRUE);
	}
	return (FALSE);
}

int	philo_is_done_eating(t_philo *p)
{
	return (DONE_EATING == p->stt);
}
