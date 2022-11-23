/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_value2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
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
