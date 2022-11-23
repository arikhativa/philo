/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

t_error_code	hand_create(t_hand **ret, t_fork *f)
{
	t_hand			*h;
	t_error_code	err;

	h = malloc(sizeof(t_hand));
	if (!h)
		return (ALLOCATION_ERROR);
	bzero(h, sizeof(t_hand));
	err = m_value_create(&(h->is_picked));
	if (SUCCESS != err)
		return (err);
	m_value_set(h->is_picked, FALSE);
	h->fork = f;
	*ret = h;
	return (SUCCESS);
}

void	hand_destroy(t_hand *h)
{
	if (h->is_picked)
		m_value_destroy(&(h->is_picked));
	bzero(h, sizeof(t_hand));
	free(h);
}

t_error_code	hand_pick_fork(t_hand *h)
{
	t_error_code	err;

	m_value_lock(h->is_picked);
	m_value_set_no_lock(h->is_picked, TRUE);
	err = fork_pick(h->fork);
	m_value_unlock(h->is_picked);
	return (err);
}

t_error_code	hand_drop_fork(t_hand *h)
{
	t_error_code	err;

	if (FALSE == m_value_get(h->is_picked))
		return (NO_FORK);
	m_value_lock(h->is_picked);
	m_value_set_no_lock(h->is_picked, FALSE);
	err = fork_drop(h->fork);
	m_value_unlock(h->is_picked);
	return (err);
}
