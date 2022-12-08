/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/08 10:05:44 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_code.h"

void	internal_error_print(const char *msg, t_error_code err)
{
	printf("%s: %d\n", msg, err);
}

t_error_code	error_code_print(t_error_code err)
{
	if (ERROR_ONE_PHILO == err)
		return (err);
	else
		internal_error_print("error code", err);
	return (err);
}
