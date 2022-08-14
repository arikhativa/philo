/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:47:25 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/14 16:10:53 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	create_th(thread_hdlrt, &ac);
	printf("hey main\n");
	return (SUCCESS);
}
