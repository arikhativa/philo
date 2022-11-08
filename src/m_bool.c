/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_bool.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:36:59 by yoav              #+#    #+#             */
/*   Updated: 2022/11/08 12:29:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_bool.h"

t_error_code	m_bool_create(t_m_bool **ret)
{
	t_m_bool	*mb;
	int			stt;

	mb = malloc(sizeof(t_m_bool));
	if (!mb)
		return (ALLOCATION_ERROR);
	stt = pthread_mutex_init(&(mb->mutex), NULL);
	if (SUCCESS != stt)
		return (MUTEX_INIT_ERROR);
	mb->on = FALSE;
	*ret = mb;
	return (SUCCESS);
}

void	m_bool_destroy(t_m_bool **obj)
{
	t_m_bool	*mb;

	mb = *obj;
	pthread_mutex_destroy(&(mb->mutex));
	bzero(mb, sizeof(t_m_bool));
	free(obj);
}

int	m_bool_is_true(t_m_bool *mb)
{
	int	ret;

	pthread_mutex_lock(&(mb->mutex));
	ret = mb->on;
	pthread_mutex_unlock(&(mb->mutex));
	return (TRUE == ret);
}

void	m_bool_set(t_m_bool *mb, int value)
{
	pthread_mutex_lock(&(mb->mutex));
	mb->on = (!!value);
	pthread_mutex_unlock(&(mb->mutex));
}

