/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

long	timer_time_to_long(t_timer *t)
{
	long	ms;

	ms = (t->tv_sec * 1000);
	ms += (t->tv_usec / 1000);
	return (ms);
}

long	timer_get_now(void)
{
	t_timer	now;

	gettimeofday(&now, NULL);
	return (timer_time_to_long(&now));
}
