/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/07 14:04:22 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAND_H
# define HAND_H

# include <stdlib.h>

# include "util.h"
# include "m_value.h"
# include "macros.h"
# include "fork.h"

typedef struct s_hand
{
	t_fork			*fork;
}	t_hand;

t_error_code	hand_create(t_hand **ret, t_fork *f);
void			hand_destroy(t_hand *h);
t_error_code	hand_pick_fork(t_hand *h);
t_error_code	hand_drop_fork(t_hand *h);

#endif
