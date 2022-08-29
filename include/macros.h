/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:57:03 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/29 15:53:17 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

typedef void *(*t_thread_handler)(void *);

# define ZERO	(0)
# define TRUE	(1)
# define FALSE	(!TRUE)

# define EAT_LIM	(5000)
# define EAT_TIME	(1000000)
# define DIE_TIME	(1000000)
# define SLEEP_TIME	(1000000)

#endif
