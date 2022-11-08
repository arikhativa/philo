/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_bool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:17:51 by yoav              #+#    #+#             */
/*   Updated: 2022/11/08 12:29:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_BOOL_H
# define MUTEX_BOOL_H

# include <stdlib.h>
# include <pthread.h>

# include "macros.h"
# include "error_code.h"

typedef struct s_m_bool
{
	int				on;
	pthread_mutex_t	mutex;
}	t_m_bool;

t_error_code	m_bool_create(t_m_bool **ret);
void			m_bool_destroy(t_m_bool **obj);
int				m_bool_is_true(t_m_bool *mb);
void			m_bool_set(t_m_bool *mb, int value);

#endif
