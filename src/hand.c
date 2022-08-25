/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:14:28 by yoav              #+#    #+#             */
/*   Updated: 2022/08/25 11:31:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

t_error_code	hand_create(t_hand *ret)
{
	ret = malloc(sizeof(t_hand));
	if (!ret)
		return (ALLOCATION_ERROR);
	bzero(ret, sizeof(t_hand));
	return (SUCCESS);
}

void	hand_destroy(t_hand *h)
{
	bzero(h, sizeof(t_hand));
	free(h);
}

t_error_code	hand_pick_fork(t_hand *h, t_fork *f)
{
	t_error_code	err;
	
	err = fork_pick(f);
	if (SUCCESS == err)
	{
		h->fork = f;
		h->is_fork = TRUE;
	}
	return (err);
}

t_error_code	hand_drop_fork(t_hand *h, t_fork *f)
{
	t_error_code	err;
	
	if (!h->is_fork)
		return (HAND_DROP_ERROR_NO_FORK);
	err = fork_drop(f);
	if (SUCCESS == err)
		bzero(h, sizeof(t_hand));
	return (err);
}
