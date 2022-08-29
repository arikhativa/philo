/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:10:41 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 15:47:19 by yoav             ###   ########.fr       */
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

// void	timer_set(t_timer *t)
// {
// 	gettimeofday(t, NULL);
// }

long	timer_get_now(void)
{
	t_timer	now;

	gettimeofday(&now, NULL);
	return (timer_time_to_long(&now));
}

// t_timer	timer_time_passed(t_timer *t)
// {
// 	t_timer	now;

// 	gettimeofday(&now, NULL);
// 	now.tv_sec - t->tv_sec;
// 	now.tv_usec - t->tv_usec;
// 	return (now);
// }
