/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/07 10:40:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

t_error_code	fork_create(t_fork **ret, int id)
{
	t_fork	*f;
	int		stt;

	f = malloc(sizeof(t_fork));
	if (!f)
		return (ALLOCATION_ERROR);
	stt = pthread_mutex_init(&(f->mutex), NULL);
	if (SUCCESS != stt)
		return (MUTEX_INIT_ERROR);
	f->id = id;
	*ret = f;
	return (SUCCESS);
}

t_error_code	fork_destroy(t_fork *f)
{
	int	stt;

	stt = pthread_mutex_destroy(&(f->mutex));
	if (SUCCESS != stt)
		return (MUTEX_DESTROY_ERROR);
	ft_bzero(f, sizeof(t_fork));
	free(f);
	return (SUCCESS);
}

t_error_code	fork_pick(t_fork *f)
{
	int	stt;

	stt = pthread_mutex_lock(&(f->mutex));
	if (SUCCESS != stt)
		return (MUTEX_LOCK_ERROR);
	return (SUCCESS);
}

t_error_code	fork_drop(t_fork *f)
{
	int	stt;

	stt = pthread_mutex_unlock(&(f->mutex));
	if (SUCCESS != stt)
		return (MUTEX_UNLOCK_ERROR);
	return (SUCCESS);
}
