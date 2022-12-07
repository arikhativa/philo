/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/07 14:09:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	odd_handler(t_philo *p)
{
	t_error_code	err;

	while (philo_is_simulation_on(p))
	{
		err = philo_pick_fork_right(p);
		if (SUCCESS != err)
			return ;
		err = philo_pick_fork_left(p);
		if (END_SIMULATION == err)
		{
			philo_drop_fork_right(p);
			return ;
		}
		philo_eat_sleep(p);
		philo_thinking(p);
	}
}

static void	even_handler(t_philo *p)
{
	t_error_code	err;

	sleep_wrapper((p->i->time_to_eat / 3));
	while (philo_is_simulation_on(p))
	{
		err = philo_pick_fork_left(p);
		if (SUCCESS != err)
			return ;
		err = philo_pick_fork_right(p);
		if (END_SIMULATION == err)
		{
			philo_drop_fork_left(p);
			return ;
		}
		philo_eat_sleep(p);
		philo_thinking(p);
	}
}

void	*philo_handler(void *arg)
{
	t_philo	*p;

	p = arg;
	if (is_even(p->id))
		even_handler(p);
	else
		odd_handler(p);
	return (NULL);
}
