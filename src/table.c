/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:02 by yoav              #+#    #+#             */
/*   Updated: 2022/11/09 11:21:39 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

t_error_code	table_create(t_table **ret, t_input	*i)
{
	t_table			*t;
	t_error_code	err;

	t = malloc(sizeof(t_table));
	if (!t)
		return (ALLOCATION_ERROR);
	bzero(t, sizeof(t_table));
	err = m_value_create(&(t->simulation_is_on));
	if (SUCCESS != err)
		return (err);
	m_value_set(t->simulation_is_on, TRUE);
	err = pthread_mutex_init(&(t->print_mutex), NULL);
	if (SUCCESS != err)
		return (MUTEX_INIT_ERROR);
	t->num_of_philo = i->philo;
	err = table_fork_list_init(t, t->num_of_philo);
	if (SUCCESS == err)
	{
		err = table_philo_list_init(t, i);
		if (SUCCESS != err)
			table_fork_list_free(t->fork_list, t->num_of_philo);
	}
	*ret = t;
	return (err);
}

void	table_destroy(t_table *t)
{
	if (t->philo_list)
		table_philo_list_free(t->philo_list, t->num_of_philo);
	if (t->fork_list)
		table_fork_list_free(t->fork_list, t->num_of_philo);
	if (t->simulation_is_on)
		m_value_destroy(&(t->simulation_is_on));
	pthread_mutex_destroy(&(t->print_mutex));
	bzero(t, sizeof(t_table));
	free(t);
}
