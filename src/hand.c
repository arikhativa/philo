/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:14:28 by yoav              #+#    #+#             */
/*   Updated: 2022/11/06 13:28:37 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

t_error_code	hand_create(t_hand **ret, t_fork *f)
{
	t_hand *h;

	h = malloc(sizeof(t_hand));
	if (!h)
		return (ALLOCATION_ERROR);
	bzero(h, sizeof(t_hand));
	h->fork = f;
	*ret = h;
	return (SUCCESS);
}

void	hand_destroy(t_hand *h)
{
	bzero(h, sizeof(t_hand));
	free(h);
}

t_error_code	hand_pick_fork(t_hand *h)
{
	t_error_code	err;
	
	err = fork_pick(h->fork);
	return (err);
}

t_error_code	hand_drop_fork(t_hand *h)
{
	t_error_code	err;

	err = fork_drop(h->fork);
	return (err);
}
