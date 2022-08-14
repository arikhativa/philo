/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:15:37 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/14 17:26:36 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

t_error_code	fork_init(t_fork *f)
{
	int	stt;

	stt = pthread_mutex_init(&(f->mutex), NULL);
	if (SUCCESS != stt)
		return (MUTEX_INIT_ERROR);
	return (SUCCESS);
}

t_error_code	fork_destroy(t_fork *f)
{
	int	stt;

	stt = pthread_mutex_destroy(&(f->mutex));
	if (SUCCESS != stt)
		return (MUTEX_DESTROY_ERROR);
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
