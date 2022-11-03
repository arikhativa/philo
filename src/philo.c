/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:47:25 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/03 15:34:50 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error_code	philo_create(t_philo **ret, int id, t_fork *l, t_fork *r, long start_time, t_input *i)
{
	t_philo 		*p;
	t_error_code	err;

	p = malloc(sizeof(t_philo));
	if (!p)
		return (ALLOCATION_ERROR);
	bzero(p, sizeof(t_philo));
	err = hand_create(&p->left_hand, l);
	if (!p)
	{
		philo_destroy(p);
		return (ALLOCATION_ERROR);
	}
	err = hand_create(&p->right_hand, r);
	if (!p)
	{
		philo_destroy(p);
		return (ALLOCATION_ERROR);
	}
	p->id = id;
	p->start_time = start_time;
	p->starvation_limit = i->time_to_die;
	p->eat_time = start_time;
	p->simulation_is_on = TRUE;
	p->i = i;
	*ret = p;
	return (err);	
}

void	philo_destroy(t_philo *p)
{
	if (p->left_hand)
		hand_destroy(p->left_hand);
	if (p->right_hand)
		hand_destroy(p->right_hand);
	bzero(p, sizeof(t_philo));
	free(p);
}
