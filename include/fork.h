/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:15:55 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/14 17:26:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>

# include "error.h"

typedef struct s_fork
{
	pthread_mutex_t mutex;
}	t_fork;

t_error_code	fork_init(t_fork *f);
t_error_code	fork_destroy(t_fork *f);
t_error_code	fork_pick(t_fork *f);
t_error_code	fork_drop(t_fork *f);

#endif
