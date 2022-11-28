/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/27 14:58:19 by yrabby           ###   ########.fr       */
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
	if (DONE_EATING == m_value_get(p->stt))
		return (FALSE);
	return (m_value_get(p->simulation_is_on));
}
