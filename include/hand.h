/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:13:19 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 13:48:55 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAND_H
# define HAND_H

# include <stdlib.h>

# include "util.h"
# include "macros.h"
# include "print_action.h"
# include "fork.h"

typedef struct s_hand
{
	int		is_fork;
	t_fork	*fork;
}	t_hand;

t_error_code	hand_create(t_hand **ret, t_fork *f);
void			hand_destroy(t_hand *h);
t_error_code	hand_pick_fork(t_hand *h);
t_error_code	hand_drop_fork(t_hand *h);

#endif
