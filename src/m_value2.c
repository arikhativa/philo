/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_value2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:57:19 by yoav              #+#    #+#             */
/*   Updated: 2022/11/09 12:22:55 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_value.h"

void	m_value_lock(t_m_value *mb)
{
	pthread_mutex_lock(&(mb->mutex));
}

void	m_value_set_no_lock(t_m_value *mb, long value)
{
	mb->value = value;
}

void	m_value_unlock(t_m_value *mb)
{
	pthread_mutex_unlock(&(mb->mutex));
}
