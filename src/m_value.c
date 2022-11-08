/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_value.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:36:59 by yoav              #+#    #+#             */
/*   Updated: 2022/11/08 12:29:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_value.h"

t_error_code	m_value_create(t_m_value **ret)
{
	t_m_value	*mb;
	int			stt;

	mb = malloc(sizeof(t_m_value));
	if (!mb)
		return (ALLOCATION_ERROR);
	stt = pthread_mutex_init(&(mb->mutex), NULL);
	if (SUCCESS != stt)
		return (MUTEX_INIT_ERROR);
	mb->on = FALSE;
	*ret = mb;
	return (SUCCESS);
}

void	m_value_destroy(t_m_value **obj)
{
	t_m_value	*mb;

	mb = *obj;
	pthread_mutex_destroy(&(mb->mutex));
	bzero(mb, sizeof(t_m_value));
	free(mb);
	*obj = NULL;
}

int	m_value_get(t_m_value *mb)
{
	int	ret;

	pthread_mutex_lock(&(mb->mutex));
	ret = mb->on;
	pthread_mutex_unlock(&(mb->mutex));
	return (TRUE == ret);
}

void	m_value_set(t_m_value *mb, int value)
{
	pthread_mutex_lock(&(mb->mutex));
	mb->on = value;
	pthread_mutex_unlock(&(mb->mutex));
}

