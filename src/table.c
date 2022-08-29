/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:02 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 12:43:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

t_error_code	table_create(t_table **ret, int num_of_philo)
{
	t_table 		*t;
	t_error_code	err;

	t = malloc(sizeof(t_table));
	if (!t)
		return (ALLOCATION_ERROR);
	bzero(t, sizeof(t_table));
	t->num_of_philo = num_of_philo;
	err = table_fork_list_init(t, num_of_philo);
	if (SUCCESS == err)
	{
		err = table_philo_list_init(t, num_of_philo);
		if (SUCCESS != err)
			table_fork_list_free(t->fork_list, t->num_of_philo);
	}
	printf("%d\n", t->num_of_philo);
	*ret = t;
	return (err);
}

void	table_destroy(t_table *t)
{
	if (t->philo_list)
		table_philo_list_free(t->philo_list, t->num_of_philo);
	if (t->fork_list)
		table_fork_list_free(t->fork_list, t->num_of_philo);
	bzero(t, sizeof(t_table));
	free(t);
}
