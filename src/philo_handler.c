/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:35:52 by yoav              #+#    #+#             */
/*   Updated: 2022/11/08 14:56:50 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// start right
// then try left
static void	odd_handler(t_philo *p)
{
	while (philo_is_simulation_on(p))
	{
		philo_pick_fork_right(p);
		philo_pick_fork_left(p);
		philo_eat_sleep(p);
		philo_thinking(p);
	}
	philo_drop_forks(p);
}

// start left only
static void	even_handler(t_philo *p)
{
	sleep_wrapper(p->i->time_to_eat);
	while (philo_is_simulation_on(p))
	{
		philo_pick_fork_left(p);
		philo_pick_fork_right(p);
		philo_eat_sleep(p);
		philo_thinking(p);
	}
	philo_drop_forks(p);
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
