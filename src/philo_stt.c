/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:37:26 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 13:58:11 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *p)
{
	p->stt = EAT;
	print_action(p->id, "is eating");
	usleep(USLEEP_TIME);
}

void	philo_sleep(t_philo *p)
{
	p->stt = SLEEP;
	print_action(p->id, "is sleeping");
	usleep(USLEEP_TIME);
}

void	philo_thinking(t_philo *p)
{
	p->stt = THINK;
	print_action(p->id, "is thinking");
}

void	philo_died(t_philo *p)
{
	p->stt = DIED;
	print_action(p->id, "died");
}
