/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/07 14:43:03 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_hdlr(t_philo *p)
{
	++p->num_of_meals;
	if (p->num_of_meals == p->i->meals_to_eat)
	{
		m_value_lock(p->stt);
		if (RUN == m_value_get_no_lock(p->stt))
			m_value_set_no_lock(p->stt, DONE_EATING);
		m_value_unlock(p->stt);
	}
}

void	philo_eat_sleep(t_philo *p)
{
	long	eat_time;

	if (!philo_is_simulation_on(p))
	{
		philo_drop_forks(p);
		return ;
	}
	print_action_lock(p);
	eat_time = timer_get_now();
	m_value_set(p->eat_time, eat_time);
	print_action_no_lock(p, "has taken a fork", eat_time);
	print_action_no_lock(p, "has taken a fork", eat_time);
	print_action_no_lock(p, "is eating", eat_time);
	eat_hdlr(p);
	print_action_unlock(p);
	sleep_wrapper(p->i->time_to_eat);
	print_action_lock(p);
	philo_drop_forks(p);
	print_action_no_lock(p, "is sleeping", timer_get_now());
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
	m_value_lock(p->eat_time);
	m_value_lock(p->stt);
	if (DONE_EATING == m_value_get_no_lock(p->stt))
	{
		m_value_unlock(p->stt);
		return (ret);
	}
	now = timer_get_now();
	if ((now - m_value_get_no_lock(p->eat_time)) > p->starvation_limit)
	{
		p->time_of_death = now;
		m_value_set_no_lock(p->stt, DIED);
		ret = TRUE;
	}
	m_value_unlock(p->eat_time);
	m_value_unlock(p->stt);
	return (ret);
}
