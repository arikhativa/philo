/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:57:03 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/03 14:44:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

typedef void *(*t_thread_handler)(void *);

# define ZERO			(0)
# define TRUE			(1)
# define FALSE			(!TRUE)
# define MIN_ARG		5
# define MAX_ARG		6

# define STARVATION_TIME	(100)
# define EAT_TIME			(300)
# define SLEEP_TIME			(30)

#endif
