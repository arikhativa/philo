/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:42:52 by yoav              #+#    #+#             */
/*   Updated: 2022/08/30 11:13:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *p, const char *msg)
{
	long	now;

	if (!p->simulation_is_on)
		return ;
	now = timer_get_now();
	printf("% 10ld % 3d %s\n", (now - p->start_time), p->id, msg);
}
