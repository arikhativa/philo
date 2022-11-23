/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_simulation1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
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

t_error_code	table_start_simulation(t_table *t)
{
	int				i;
	t_error_code	err;

	i = 0;
	while (i < t->num_of_philo)
	{
		err = philo_start_simulation(t->philo_list[i]);
		if (SUCCESS != err)
		{
			(void)stop_list(t->philo_list, i);
			return (err);
		}
		++i;
	}
	return (SUCCESS);
}
