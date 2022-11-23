/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (is_even(p->id))
		even_handler(p);
	else
		odd_handler(p);
	return (NULL);
}
