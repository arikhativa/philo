/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:02 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 12:31:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

void	philo_list_free(t_philo **list, int size)
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

void	fork_list_free(t_fork **list, int size)
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

static inline t_error_code	init_forks(t_table *t, int num_of_philo)
{
	t_error_code	err;
	int	i;
	
	t->fork_list = malloc(sizeof(t_fork *) * num_of_philo);
	if (!t->fork_list)
		return (ALLOCATION_ERROR);
	i = 0;
	while (i < num_of_philo)
	{
		err = fork_create(t->fork_list + i);
		if (SUCCESS != err)
			break ;
		++i;
	}
	if (SUCCESS != err)
		fork_list_free(t->fork_list, i);
	return (err);
}

static inline t_fork	*get_philo_left_fork(t_fork **fork_list, int i)
{
	return (fork_list[i]);
}

static inline t_fork	*get_philo_right_fork(t_fork **fork_list, int i, int num_of_philo)
{
	i = (num_of_philo + i) % (num_of_philo + i);
	return (fork_list[i]);
}

static inline t_error_code	init_philos(t_table *t, int num_of_philo)
{
	t_error_code	err;
	t_fork			*l;
	t_fork			*r;
	int	i;
	
	t->philo_list = malloc(sizeof(t_philo *) * num_of_philo);
	if (!t->philo_list)
		return (ALLOCATION_ERROR);
	i = 0;
	while (i < num_of_philo)
	{
		l = get_philo_left_fork(t->fork_list, i);
		r = get_philo_right_fork(t->fork_list, i, num_of_philo);
		err = philo_create((t->philo_list + i), i, l, r);
		if (SUCCESS != err)
			break ;
		++i;
	}
	if (SUCCESS != err)
		philo_list_free(t->philo_list, i);
	return (err);
}

t_error_code	table_create(t_table **ret, int num_of_philo)
{
	t_table 		*t;
	t_error_code	err;

	t = malloc(sizeof(t_table));
	if (!t)
		return (ALLOCATION_ERROR);
	bzero(t, sizeof(t_table));
	t->num_of_philo = num_of_philo;
	err = init_forks(t, num_of_philo);
	if (SUCCESS == err)
	{
		err = init_philos(t, num_of_philo);
		if (SUCCESS != err)
			fork_list_free(t->fork_list, t->num_of_philo);
	}
	printf("%d\n", t->num_of_philo);
	*ret = t;
	return (err);
}

void	table_destroy(t_table *t)
{
	if (t->philo_list)
		philo_list_free(t->philo_list, t->num_of_philo);
	if (t->fork_list)
		fork_list_free(t->fork_list, t->num_of_philo);
	bzero(t, sizeof(t_table));
	free(t);
}
