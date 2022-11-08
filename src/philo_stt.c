/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:37:26 by yoav              #+#    #+#             */
/*   Updated: 2022/11/08 15:03:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat_sleep(t_philo *p)
{
	if (!philo_is_simulation_on(p))
		return ;
	p->eat_time = timer_get_now();
	print_action_lock(p);
	print_action_no_lock(p, "is eating", p->eat_time);
	++p->num_of_meals;
	if (p->num_of_meals == p->i->meals_to_eat)
		p->stt = DONE_EATING;
	sleep_wrapper(p->i->time_to_eat);
	print_action_no_lock(p, "is sleeping", p->eat_time + p->i->time_to_eat);
	print_action_unlock(p);
	philo_drop_forks(p);
	sleep_wrapper(p->i->time_to_sleep);
}

void	philo_thinking(t_philo *p)
{
	if (!philo_is_simulation_on(p))
		return ;
	print_action(p, "is thinking", p->eat_time + p->i->time_to_eat \
		+ p->i->time_to_sleep);
}

int	philo_check_dead(t_philo *p)
{
	long	now;

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
