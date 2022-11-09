/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_value.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:57:31 by yoav              #+#    #+#             */
/*   Updated: 2022/11/09 12:34:09 by yoav             ###   ########.fr       */
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
	bzero(mb, sizeof(t_m_value));
	stt = pthread_mutex_init(&(mb->mutex), NULL);
	if (SUCCESS != stt)
		return (MUTEX_INIT_ERROR);
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

long	m_value_get(t_m_value *mb)
{
	long	ret;

	pthread_mutex_lock(&(mb->mutex));
	ret = mb->value;
	pthread_mutex_unlock(&(mb->mutex));
	return (ret);
}

void	m_value_set(t_m_value *mb, long value)
{
	pthread_mutex_lock(&(mb->mutex));
	mb->value = value;
	pthread_mutex_unlock(&(mb->mutex));
}
