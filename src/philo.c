/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:47:25 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/29 11:39:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void philo_handler(void *arg)
// {
// 	printf("philo_handler\n");
// }
// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

void	philo_destroy(t_philo *p)
{
	if (p->left_hand)
		hand_destroy(p->left_hand);
	if (p->right_hand)
		hand_destroy(p->right_hand);
	bzero(p, sizeof(t_philo));
	free(p);
}

t_error_code	philo_create(t_philo *ret, int id, t_fork *l, t_fork *r)
{
	t_error_code	err;

	ret = malloc(sizeof(t_philo));
	if (!ret)
		return (ALLOCATION_ERROR);
	bzero(ret, sizeof(t_philo));
	err = hand_create(ret->left_hand, l);
	if (!ret)
	{
		philo_destroy(ret);
		return (ALLOCATION_ERROR);
	}
	err = hand_create(ret->right_hand, r);
	if (!ret)
	{
		philo_destroy(ret);
		return (ALLOCATION_ERROR);
	}
	ret->id = id;
	return (err);	
}

// t_philo	philo_start(int id)
// {
// 	// stt = pthread_create(&tid, NULL, philo_handler, hdlr_arg);
	
// }

// void	*thread_hdlrt(void *args)
// {
// 	sleep(1);
// 	printf("the1 %d\n", *(int *)args);
// 	return (NULL);
// }

// void	create_th(t_thread_handler hdlr, void *restrict hdlr_arg)
// {
// 	pthread_t	tid;
// 	int			stt;
	
// 	stt = pthread_create(&tid, NULL, hdlr, hdlr_arg);
// 	pthread_join(tid, NULL);
// }

