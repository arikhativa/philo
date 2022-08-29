/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:10:51 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 15:42:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# include <sys/time.h>
# include <stdio.h>
# include <stddef.h>

typedef struct timeval t_timer;

long	timer_get_now(void);

#endif
