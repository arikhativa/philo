/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:49:28 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/25 11:30:44 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum s_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	MUTEX_INIT_ERROR,
	MUTEX_DESTROY_ERROR,
	MUTEX_LOCK_ERROR,
	HAND_DROP_ERROR_NO_FORK,
	ALLOCATION_ERROR,
	MUTEX_UNLOCK_ERROR,
}	t_error_code;

#endif
