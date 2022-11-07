/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:38:03 by yoav              #+#    #+#             */
/*   Updated: 2022/11/07 11:46:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

void	table_fork_list_free(t_fork **list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		fork_destroy(list[i]);
		list[i] = NULL;
		++i;
	}
	free(list);
}

t_error_code	table_fork_list_init(t_table *t, int num_of_philo)
{
	t_error_code	err;
	int				i;

	t->fork_list = malloc(sizeof(t_fork *) * num_of_philo);
	if (!t->fork_list)
		return (ALLOCATION_ERROR);
	i = 0;
	while (i < num_of_philo)
	{
		err = fork_create(t->fork_list + i, i);
		if (SUCCESS != err)
			break ;
		++i;
	}
	if (SUCCESS != err)
		table_fork_list_free(t->fork_list, i);
	return (err);
}

t_fork	*table_get_left_fork_by_philo(t_fork **fork_list, int i)
{
	return (fork_list[i]);
}

t_fork	*table_get_right_fork_by_philo(t_fork **fork_list, \
	int i, int num_of_philo)
{
	i = (num_of_philo - 1 + i) % (num_of_philo);
	return (fork_list[i]);
}
