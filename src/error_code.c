/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:43:31 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 12:55:39 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_code.h"

void	internal_error_print(const char *msg, t_error_code err)
{
	printf("%s: %d\n", msg, err);
}

void	error_code_print(t_error_code err)
{
	if (ERROR == err)
		internal_error_print("ERROR", err);
	else if (SUCCESS == err)
		internal_error_print("SUCCESS", err);
	else if (MUTEX_INIT_ERROR == err)
		internal_error_print("MUTEX_INIT_ERROR", err);
	else if (MUTEX_DESTROY_ERROR == err)
		internal_error_print("MUTEX_DESTROY_ERROR", err);
	else if (MUTEX_LOCK_ERROR == err)
		internal_error_print("MUTEX_LOCK_ERROR", err);
	else if (HAND_DROP_ERROR_NO_FORK == err)
		internal_error_print("HAND_DROP_ERROR_NO_FORK", err);
	else if (ALLOCATION_ERROR == err)
		internal_error_print("ALLOCATION_ERROR", err);
	else if (MUTEX_UNLOCK_ERROR == err)
		internal_error_print("MUTEX_UNLOCK_ERROR", err);
	else if (PTHREAD_JOIN_ERROR == err)
		internal_error_print("PTHREAD_JOIN_ERROR", err);
	else if (PTHREAD_CREATE_ERROR == err)
		internal_error_print("PTHREAD_CREATE_ERROR", err);
	else
		internal_error_print("UNKNOWN_ERROR", err);
}