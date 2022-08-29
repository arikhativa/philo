/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:15:37 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/29 12:19:22 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

t_error_code	fork_create(t_fork **ret)
{
	t_fork *f;
	int		stt;

	f = malloc(sizeof(t_fork));
	if (!f)
		return (ALLOCATION_ERROR);
	stt = pthread_mutex_init(&(f->mutex), NULL);
	if (SUCCESS != stt)
		return (MUTEX_INIT_ERROR);
	*ret = f;
	return (SUCCESS);
}

t_error_code	fork_destroy(t_fork *f)
{
	int	stt;

	stt = pthread_mutex_destroy(&(f->mutex));
	if (SUCCESS != stt)
		return (MUTEX_DESTROY_ERROR);
	bzero(f, sizeof(t_fork));
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
