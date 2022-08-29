/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:06:37 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 15:55:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_philo(t_philo *p)
{
	printf("ph: %d fork_l: %d fork_r: %d\n",p->id,p->left_hand->fork->id,p->right_hand->fork->id);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_error_code	err;
	t_table			*t;

	err = table_create(&t, 3);
	if (SUCCESS != err)
	{
		error_code_print(err);
		return (err);
	}
	table_start_simulation(t);
	table_stop_simulation(t);
	table_destroy(t);
	return (SUCCESS);
}
