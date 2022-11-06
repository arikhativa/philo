/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:14:28 by yoav              #+#    #+#             */
/*   Updated: 2022/11/06 12:50:19 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

t_error_code	hand_create(t_hand **ret, t_fork *f)
{
	t_hand *h;

	h = malloc(sizeof(t_hand));
	if (!h)
		return (ALLOCATION_ERROR);
	if (SUCCESS != pthread_mutex_init(&(h->check_fork), NULL))
		return (MUTEX_INIT_ERROR);
	bzero(h, sizeof(t_hand));
	h->fork = f;
	*ret = h;
	return (SUCCESS);
}

void	hand_destroy(t_hand *h)
{
	pthread_mutex_destroy(&(h->check_fork));
	bzero(h, sizeof(t_hand));
	free(h);
}

t_error_code	hand_pick_fork(t_hand *h)
{
	t_error_code	err;
	int				is_fork_used;
	
	pthread_mutex_lock(&(h->check_fork));
	is_fork_used = h->fork->is_used;
	pthread_mutex_unlock(&(h->check_fork));
	if (is_fork_used)
		return (FORK_IS_USED);
	pthread_mutex_lock(&(h->check_fork));
	err = fork_pick(h->fork);
	if (SUCCESS == err)
		h->fork->is_used = TRUE;
	pthread_mutex_unlock(&(h->check_fork));
	return (err);
}

t_error_code	hand_drop_fork(t_hand *h)
{
	t_error_code	err;
	int				is_fork_used;

	pthread_mutex_lock(&(h->check_fork));
	is_fork_used = h->fork->is_used;
	pthread_mutex_unlock(&(h->check_fork));
	if (!is_fork_used)
		return (HAND_DROP_ERROR_NO_FORK);
	pthread_mutex_lock(&(h->check_fork));
	err = fork_drop(h->fork);
	if (SUCCESS == err)
		h->fork->is_used = FALSE;
	pthread_mutex_unlock(&(h->check_fork));
	return (err);
}
