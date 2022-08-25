/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:13:19 by yoav              #+#    #+#             */
/*   Updated: 2022/08/25 11:23:22 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAND_H
# define HAND_H

# include <stdlib.h>

# include "util.h"
# include "macros.h"
# include "fork.h"

typedef struct s_hand
{
	int		is_fork;
	t_fork	*fork;
}	t_hand;

#endif
