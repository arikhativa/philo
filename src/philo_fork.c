/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error_code	philo_pick_fork_left(t_philo *p)
{
	t_error_code	err;

	if (!philo_is_simulation_on(p))
		return (END_SIMULATION);
	err = hand_pick_fork(p->left_hand);
	return (err);
}

t_error_code	philo_pick_fork_right(t_philo *p)
{
	t_error_code	err;

	if (!philo_is_simulation_on(p))
		return (END_SIMULATION);
	err = hand_pick_fork(p->right_hand);
	return (err);
}

void	philo_drop_fork_right(t_philo *p)
{
	hand_drop_fork(p->right_hand);
}

void	philo_drop_fork_left(t_philo *p)
{
	hand_drop_fork(p->left_hand);
}

void	philo_drop_forks(t_philo *p)
{
	philo_drop_fork_left(p);
	philo_drop_fork_right(p);
}
