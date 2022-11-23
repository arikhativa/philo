/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:36 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <stdlib.h>
# include <pthread.h>

# include "util.h"
# include "error_code.h"

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}	t_fork;

t_error_code	fork_create(t_fork **ret, int id);
t_error_code	fork_destroy(t_fork *f);
t_error_code	fork_pick(t_fork *f);
t_error_code	fork_drop(t_fork *f);

#endif
