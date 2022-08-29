/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:35:52 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 14:06:50 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// start right
// then try left
static void	even_handler(t_philo *p)
{
	t_error_code	err;

	while (1)
	{
		err = philo_pick_fork_right(p);
		if (SUCCESS == err)
		{
			err = philo_pick_fork_left(p);
			if (SUCCESS == err)
			{
				philo_eat(p);
				philo_drop_forks(p);
				philo_sleep(p);
				philo_thinking(p);
			}
		}
	}
}

// start left only
static void	odd_handler(t_philo *p)
{
	t_error_code	err;

	while (1)
	{
		err = philo_pick_fork_left(p);
		if (SUCCESS == err)
		{
			err = philo_pick_fork_right(p);
			if (SUCCESS == err)
			{
				philo_eat(p);
				philo_drop_forks(p);
				philo_sleep(p);
				philo_thinking(p);
			}
			else
				philo_drop_fork_left(p);
		}
	}
}

void	*philo_handler(void *arg)
{
	t_philo	*p;

	p = arg;
	philo_thinking(p);
	if (is_even(p->id))
		even_handler(p);
	else
		odd_handler(p);
	return (NULL);
}
