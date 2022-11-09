/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:37:26 by yoav              #+#    #+#             */
/*   Updated: 2022/11/09 12:34:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat_sleep(t_philo *p)
{
	long	eat_time;

	if (!philo_is_simulation_on(p))
		return ;
	print_action_lock(p);
	eat_time = timer_get_now();
	m_value_set(p->eat_time, eat_time);
	print_action_no_lock(p, "has taken a fork", eat_time);
	print_action_no_lock(p, "has taken a fork", eat_time);
	print_action_no_lock(p, "is eating", eat_time);
	++p->num_of_meals;
	if (p->num_of_meals == p->i->meals_to_eat)
		p->stt = DONE_EATING;
	print_action_unlock(p);
	sleep_wrapper(p->i->time_to_eat);
	print_action_lock(p);
	print_action_no_lock(p, "is sleeping", timer_get_now());
	philo_drop_forks(p);
	print_action_unlock(p);
	sleep_wrapper(p->i->time_to_sleep);
}

void	philo_thinking(t_philo *p)
{
	if (!philo_is_simulation_on(p))
		return ;
	print_action(p, "is thinking", timer_get_now());
}

int	philo_check_dead(t_philo *p)
{
	long	now;
	int		ret;

	ret = FALSE;
	if (DONE_EATING == p->stt)
		return (ret);
	now = timer_get_now();
	if ((now - m_value_get(p->eat_time)) > p->starvation_limit)
	{
		p->time_of_death = now;
		p->stt = DIED;
		ret = TRUE;
	}
	return (ret);
}
