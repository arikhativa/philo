/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:06:37 by yoav              #+#    #+#             */
/*   Updated: 2022/11/03 16:15:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_philo(t_philo *p)
{
	printf("ph: %d fork_l: %d fork_r: %d\n",p->id,p->left_hand->fork->id,p->right_hand->fork->id);
}

int	main(int ac, char **av)
{
	t_error_code	err;
	t_table			*t;
	t_input			*i;

	err = input_create(&i);
	if (SUCCESS != err)
		return error_code_print(err);
	err = input_init(i, ac, av);
	if (SUCCESS != err)
		return error_code_print(err);
	err = table_create(&t, i);
	if (SUCCESS != err)
		return (error_code_print(err));
	table_start_simulation(t);
	table_monitor_simulation(t);
	table_stop_simulation(t);
	table_destroy(t);
	input_destroy(&i);
	return (SUCCESS);
}
