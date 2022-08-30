/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:01:45 by yoav              #+#    #+#             */
/*   Updated: 2022/08/30 11:12:48 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error_code	philo_pick_fork_left(t_philo *p)
{
	t_error_code	err;
	
	if (p->left_hand->is_fork)
		return (SUCCESS);
	err = hand_pick_fork(p->left_hand);
	if (SUCCESS == err)
		print_action(p, "has taken a fork");
	return (err);
}

t_error_code	philo_pick_fork_right(t_philo *p)
{
	t_error_code	err;
	
	if (p->right_hand->is_fork)
		return (SUCCESS);
	err = hand_pick_fork(p->right_hand);
	if (SUCCESS == err)
		print_action(p, "has taken a fork");
	return (err);
}

void	philo_drop_fork_right(t_philo *p)
{
	t_error_code	err;

	err = hand_drop_fork(p->right_hand);
	if (SUCCESS != err)
		error_code_print(DROP_FORK_ERROR);
}

void	philo_drop_fork_left(t_philo *p)
{
	t_error_code	err;

	err = hand_drop_fork(p->left_hand);
	if (SUCCESS != err)
		error_code_print(DROP_FORK_ERROR);
}

void	philo_drop_forks(t_philo *p)
{
	philo_drop_fork_left(p);
	philo_drop_fork_right(p);
}
