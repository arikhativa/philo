/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_simulation1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/07 18:00:52 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

t_error_code	stop_list(t_philo **list, int size)
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

static t_error_code	loop(t_table *t, int i, t_philo_handler f, int is_sleep)
{
	t_error_code	err;

	while (i < t->num_of_philo)
	{
		err = philo_start_simulation(t->philo_list[i], f);
		if (SUCCESS != err)
		{
			(void)stop_list(t->philo_list, i);
			return (err);
		}
		i += 2;
		if (is_sleep)
			sleep_wrapper(t->input->time_to_eat / 2);
	}
	return (SUCCESS);
}

t_error_code	table_start_simulation(t_table *t)
{
	t_error_code	err;
	t_philo_handler	f;

	if (is_even(t->input->philo))
	{
		f = philo_even_handler;
		err = loop(t, 0, f, FALSE);
		if (SUCCESS != err)
			return (err);
		sleep_wrapper(t->input->time_to_eat / 2);
		err = loop(t, 1, f, FALSE);
		if (SUCCESS != err)
			return (err);
	}
	else
	{
		f = philo_odd_handler;
		err = loop(t, 0, f, TRUE);
		if (SUCCESS != err)
			return (err);
		err = loop(t, 1, f, TRUE);
		if (SUCCESS != err)
			return (err);
	}
	return (SUCCESS);
}
