/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:10:41 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 17:56:10 by yoav             ###   ########.fr       */
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
