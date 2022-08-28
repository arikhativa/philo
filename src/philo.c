/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:47:25 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/28 22:11:00 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_handler(void *arg)
{
	printf("philo_handler\n");
}

t_philo	philo_create()
{
	pthread_t	tid;
	int			stt;
	void *restrict hdlr_arg;
	
	stt = pthread_create(&tid, NULL, philo_handler, hdlr_arg);
	pthread_join(tid, NULL);
}



void	*thread_hdlrt(void *args)
{
	sleep(1);
	printf("the1 %d\n", *(int *)args);
	return (NULL);
}

void	create_th(t_thread_handler hdlr, void *restrict hdlr_arg)
{
	pthread_t	tid;
	int			stt;
	
	stt = pthread_create(&tid, NULL, hdlr, hdlr_arg);
	pthread_join(tid, NULL);
}

