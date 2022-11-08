/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:35:52 by yoav              #+#    #+#             */
/*   Updated: 2022/11/08 12:05:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// start right
// then try left
static void	odd_handler(t_philo *p)
{
	t_error_code	err;

	while (p->simulation_is_on)
	{
		if (TRUE == philo_check_dead(p) || TRUE == philo_is_done_eating(p))
			return ;
		err = philo_pick_fork_right(p);
		if (SUCCESS == err)
		{
			err = philo_pick_fork_left(p);
			if (SUCCESS == err)
			{
				philo_eat(p);
				philo_sleep(p);
				philo_thinking(p);
			}
		}
	}
}

// start left only
static void	even_handler(t_philo *p)
{
	t_error_code	err;

	sleep_wrapper(p->i->time_to_eat);
	while (p->simulation_is_on)
	{
		if (TRUE == philo_check_dead(p) || TRUE == philo_is_done_eating(p))
			return ;
		err = philo_pick_fork_left(p);
		if (SUCCESS == err)
		{
			err = philo_pick_fork_right(p);
			if (SUCCESS == err)
			{
				philo_eat(p);
				philo_sleep(p);
				philo_thinking(p);
			}
		}
	}
}

void	*philo_handler(void *arg)
{
	t_philo	*p;

	p = arg;
	if (!is_even(p->id))
	// if (!is_even(p->id) && !is_last_philo(p->id, p->i->philo))
		odd_handler(p);
	else
		even_handler(p);
	return (NULL);
}
