/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:17:49 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:17:50 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H

# include <stdio.h>

typedef enum s_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	MUTEX_INIT_ERROR = 1,
	MUTEX_DESTROY_ERROR = 2,
	MUTEX_LOCK_ERROR = 3,
	HAND_DROP_ERROR_NO_FORK = 4,
	ALLOCATION_ERROR = 5,
	DROP_FORK_ERROR = 6,
	PTHREAD_JOIN_ERROR,
	PTHREAD_CREATE_ERROR,
	MUTEX_UNLOCK_ERROR,
	ERROR_MISSING_ARG,
	FORK_IS_USED,
	ERROR_ONE_PHILO,
	ERROR_TOO_MANY_ARG,
	ERROR_NON_DIGIT_ARG,
	END_SIMULATION,
	NO_FORK,
}	t_error_code;

t_error_code	error_code_print(t_error_code err);

#endif
