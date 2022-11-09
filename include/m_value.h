/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_value.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:55:24 by yoav              #+#    #+#             */
/*   Updated: 2022/11/09 11:55:44 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_VALUE_H
# define M_VALUE_H

# include <stdlib.h>
# include <pthread.h>

# include "util.h"
# include "macros.h"
# include "error_code.h"

typedef struct s_m_value
{
	int				on;
	pthread_mutex_t	mutex;
}	t_m_value;

t_error_code	m_value_create(t_m_value **ret);
void			m_value_destroy(t_m_value **obj);
int				m_value_get(t_m_value *mb);
void			m_value_set(t_m_value *mb, int value);
void			m_value_lock(t_m_value *mb);
void			m_value_set_no_lock(t_m_value *mb, int value);
void			m_value_unlock(t_m_value *mb);

#endif
