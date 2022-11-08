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

void	m_value_lock(t_m_value *mb)
{
	pthread_mutex_lock(&(mb->mutex));
}

void	m_value_set_no_lock(t_m_value *mb, int value)
{
	mb->on = value;
}

void	m_value_unlock(t_m_value *mb)
{
	pthread_mutex_unlock(&(mb->mutex));
}
