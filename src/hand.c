/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/07 14:05:59 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

t_error_code	hand_create(t_hand **ret, t_fork *f)
{
	t_hand			*h;

	h = malloc(sizeof(t_hand));
	if (!h)
		return (ALLOCATION_ERROR);
	ft_bzero(h, sizeof(t_hand));
	h->fork = f;
	*ret = h;
	return (SUCCESS);
}

void	hand_destroy(t_hand *h)
{
	ft_bzero(h, sizeof(t_hand));
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
