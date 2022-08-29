/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:49:28 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/29 13:55:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H

# include <stdio.h>

typedef enum s_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	MUTEX_INIT_ERROR,
	MUTEX_DESTROY_ERROR,
	MUTEX_LOCK_ERROR,
	HAND_DROP_ERROR_NO_FORK,
	ALLOCATION_ERROR,
	DROP_FORK_ERROR,
	PTHREAD_JOIN_ERROR,
	PTHREAD_CREATE_ERROR,
	MUTEX_UNLOCK_ERROR,
}	t_error_code;

void	error_code_print(t_error_code err);

#endif
