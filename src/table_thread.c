/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:45:27 by yoav              #+#    #+#             */
/*   Updated: 2022/11/06 10:22:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

static inline t_error_code	stop_list(t_philo **list, int size)
{
	t_error_code	err;
	int				i;

	i = 0;
	while (i < size)
	{
		err = philo_stop_simulation(list[i]);
		if (SUCCESS != err)
			return (err);
		++i;
	}
	return (SUCCESS);
}

t_error_code	table_start_simulation(t_table *t)
{
	int				i;
	t_error_code	err;

	i = 0;
	while (i < t->num_of_philo)
	{
		err = philo_start_simulation(t->philo_list[t->num_of_philo - i - 1]);
		if (SUCCESS != err)
		{
			(void)stop_list(t->philo_list, i);
			return (err);
		}
		++i;
	}
	return (SUCCESS);
}

static void	print_dead_if_needed(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->num_of_philo)
	{
		if (DIED == t->philo_list[i]->stt)
		{
			print_dead(t->philo_list[i], "died");
			return ;
		}
		++i;
	}
}

void	table_monitor_simulation(t_table *t)
{
	int	loop;

	loop = TRUE;
	while (loop)
	{
		if (table_philo_list_is_dead(t->philo_list, t->num_of_philo))
		{
			loop = FALSE;
			table_philo_list_stop(t->philo_list, t->num_of_philo);
		}
	}
	print_dead_if_needed(t);
}	

t_error_code	table_stop_simulation(t_table *t)
{
	return (stop_list(t->philo_list, t->num_of_philo));
}
