/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/07 13:55:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

int	table_philo_list_is_dead(t_philo **list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (philo_check_dead(list[i]))
			return (TRUE);
		++i;
	}
	return (FALSE);
}

int	table_philo_list_is_done(t_philo **list, int size)
{
	int	i;
	int	p_done_eating;

	i = 0;
	p_done_eating = 0;
	while (i < size)
	{
		if (DONE_EATING == m_value_get_no_lock(list[i]->stt))
			++p_done_eating;
		++i;
	}
	return (p_done_eating == size);
}

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

t_error_code	table_philo_list_init(t_table *t, t_input *input)
{
	t_error_code	err;
	t_fork			*l;
	t_fork			*r;
	long			start_time;
	int				i;

	t->philo_list = malloc(sizeof(t_philo *) * t->num_of_philo);
	if (!t->philo_list)
		return (ALLOCATION_ERROR);
	start_time = timer_get_now();
	i = 0;
	while (i < t->num_of_philo)
	{
		l = table_get_left_fork_by_philo(t->fork_list, i);
		r = table_get_right_fork_by_philo(t->fork_list, i, t->num_of_philo);
		err = philo_create((t->philo_list + i), l, r, t->simulation_is_on);
		if (SUCCESS != err)
			break ;
		philo_init(t->philo_list[i], (i + 1), start_time, input);
		philo_init2(t->philo_list[i], &(t->print_mutex));
		++i;
	}
	if (SUCCESS != err)
		table_philo_list_free(t->philo_list, i);
	return (err);
}
