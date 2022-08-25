/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:48:14 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/25 11:13:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <printf.h>
# include <pthread.h>
# include <unistd.h>

# include "hand.h"
# include "fork.h"
# include "macros.h"
# include "error.h"

typedef enum e_philo_stt
{
	EAT,
	THINK,
	SLEEP,
}	t_philo_stt;

typedef struct s_philo
{
	t_philo_stt	stt;
	s_hand		*left;
	s_hand		*right;
}	t_philo;

#endif
