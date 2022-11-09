/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:36:59 by yoav              #+#    #+#             */
/*   Updated: 2022/11/09 11:53:58 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error_code	philo_start_simulation(t_philo *p)
{
	int	stt;

	stt = pthread_create(&(p->tid), NULL, philo_handler, p);
	if (SUCCESS != stt)
		return (PTHREAD_CREATE_ERROR);
	return (SUCCESS);
}

t_error_code	philo_stop_simulation(t_philo *p)
{
	int	stt;

	stt = pthread_join(p->tid, NULL);
	if (SUCCESS != stt)
		return (PTHREAD_JOIN_ERROR);
	return (SUCCESS);
}

int	philo_is_simulation_on(t_philo *p)
{
	if (DONE_EATING == p->stt)
		return (FALSE);
	return (m_value_get(p->simulation_is_on));
}
