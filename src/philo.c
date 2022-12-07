/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/07 10:40:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error_code	philo_create(t_philo **ret, t_fork *l, t_fork *r, \
	t_m_value *simulation_is_on)
{
	t_philo			*p;
	t_error_code	err;

	p = malloc(sizeof(t_philo));
	if (!p)
		return (ALLOCATION_ERROR);
	ft_bzero(p, sizeof(t_philo));
	err = hand_create(&p->left_hand, l);
	if (SUCCESS != err)
		return (err);
	err = hand_create(&p->right_hand, r);
	if (SUCCESS != err)
		return (err);
	err = m_value_create(&(p->stt));
	if (SUCCESS != err)
		return (err);
	err = m_value_create(&(p->eat_time));
	if (SUCCESS != err)
		return (err);
	p->simulation_is_on = simulation_is_on;
	*ret = p;
	return (err);
}

void	philo_init(t_philo *p, int id, long start_time, t_input *i)
{
	p->id = id;
	p->start_time = start_time;
	p->starvation_limit = i->time_to_die;
	m_value_set(p->eat_time, start_time);
	p->i = i;
}

void	philo_init2(t_philo *p, pthread_mutex_t *print_mutex)
{
	p->print_mutex = print_mutex;
}

void	philo_destroy(t_philo *p)
{
	if (p->left_hand)
		hand_destroy(p->left_hand);
	if (p->right_hand)
		hand_destroy(p->right_hand);
	if (p->eat_time)
		m_value_destroy(&(p->eat_time));
	if (p->stt)
		m_value_destroy(&(p->stt));
	ft_bzero(p, sizeof(t_philo));
	free(p);
}
