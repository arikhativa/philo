/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:38:50 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 15:43:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

void	table_philo_list_free(t_philo **list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		philo_destroy(list[i]);
		list[i] = NULL;
		++i;
	}
	free(list);
}

t_error_code	table_philo_list_init(t_table *t, int num_of_philo)
{
	t_error_code	err;
	t_fork			*l;
	t_fork			*r;
	long	start_time;
	int	i;
	
	t->philo_list = malloc(sizeof(t_philo *) * num_of_philo);
	if (!t->philo_list)
		return (ALLOCATION_ERROR);
	start_time = timer_get_now();
	i = 0;
	while (i < num_of_philo)
	{
		l = table_get_left_fork_by_philo(t->fork_list, i);
		r = table_get_right_fork_by_philo(t->fork_list, i, num_of_philo);
		err = philo_create((t->philo_list + i), i, l, r, start_time);
		if (SUCCESS != err)
			break ;
		++i;
	}
	if (SUCCESS != err)
		table_philo_list_free(t->philo_list, i);
	return (err);
}
