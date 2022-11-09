/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_simulation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:45:27 by yoav              #+#    #+#             */
/*   Updated: 2022/11/09 11:24:39 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

static void	print_dead_if_needed(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->num_of_philo)
	{
		if (DIED == t->philo_list[i]->stt)
		{
			print_dead(t->philo_list[i]);
			return ;
		}
		++i;
	}
}

static int	should_stop_simulation(t_table *t)
{
	int	is_p_dead;
	int	is_done_eating;

	is_done_eating = table_philo_list_is_done(t->philo_list, t->num_of_philo);
	is_p_dead = table_philo_list_is_dead(t->philo_list, t->num_of_philo);
	return (is_done_eating || is_p_dead);
}

void	table_monitor_simulation(t_table *t)
{
	int	loop;

	loop = TRUE;
	while (loop)
	{
		pthread_mutex_lock(&(t->print_mutex));
		if (should_stop_simulation(t))
		{
			loop = FALSE;
			m_value_set(t->simulation_is_on, FALSE);
		}
		pthread_mutex_unlock(&(t->print_mutex));
	}
}	

t_error_code	table_stop_simulation(t_table *t)
{
	t_error_code	err;

	err = stop_list(t->philo_list, t->num_of_philo);
	if (SUCCESS == err)
		print_dead_if_needed(t);
	return (err);
}
